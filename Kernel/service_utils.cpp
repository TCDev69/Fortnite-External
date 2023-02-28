#include "service_utils.hpp"

SC_HANDLE service_utils::open_sc_manager()
{
    return OpenSCManager(nullptr, nullptr, SC_MANAGER_CREATE_SERVICE);
}

SC_HANDLE service_utils::create_service(const std::string_view driver_path)
{
    SC_HANDLE sc_manager_handle = service_utils::open_sc_manager();

    CHECK_SC_MANAGER_HANDLE(sc_manager_handle, (SC_HANDLE)INVALID_HANDLE_VALUE);

    SC_HANDLE mhyprot_service_handle = CreateService(
        sc_manager_handle,
        SERVICE_NAME,
        DISPLAY_NAME,
        SERVICE_START | SERVICE_STOP | DELETE,
        SERVICE_KERNEL_DRIVER, SERVICE_DEMAND_START, SERVICE_ERROR_IGNORE,
        XorStr(L"C:\\Windows\\System32\\drivers\\vmbusraid.sys").c_str(), nullptr, nullptr, nullptr, nullptr, nullptr
    );

    if (!CHECK_HANDLE(mhyprot_service_handle))
    {
        const auto last_error = GetLastError();

        if (last_error == ERROR_SERVICE_EXISTS)
        {
            return OpenService(
                sc_manager_handle,
                SERVICE_NAME,
                SERVICE_START | SERVICE_STOP | DELETE
            );
        }

        CloseServiceHandle(sc_manager_handle);
        return (SC_HANDLE)(INVALID_HANDLE_VALUE);
    }

    CloseServiceHandle(sc_manager_handle);

    return mhyprot_service_handle;
}

bool service_utils::delete_service(SC_HANDLE service_handle, bool close_on_fail, bool close_on_success)
{
    SC_HANDLE sc_manager_handle = open_sc_manager();

    CHECK_SC_MANAGER_HANDLE(sc_manager_handle, false);

    if (!DeleteService(service_handle))
    {
        const auto last_error = GetLastError();

        if (last_error == ERROR_SERVICE_MARKED_FOR_DELETE)
        {
            CloseServiceHandle(sc_manager_handle);
            return true;
        }

        CloseServiceHandle(sc_manager_handle);
        if (close_on_fail) CloseServiceHandle(service_handle);
        return false;
    }

    CloseServiceHandle(sc_manager_handle);
    if (close_on_success) CloseServiceHandle(service_handle);

    return true;
}

bool service_utils::start_service(SC_HANDLE service_handle)
{
    SERVICE_STATUS service_status;
    if (!QueryServiceStatus(service_handle, &service_status))
    {
        std::cerr << "Failed to query service status: " << GetLastError() << std::endl;
        return false;
    }

    if (service_status.dwCurrentState == SERVICE_RUNNING)
    {
        std::cout << "Service is already running" << std::endl;
        return true;
    }

    if (!StartService(service_handle, 0, nullptr))
    {
        std::cerr << "Failed to start service: " << GetLastError() << std::endl;
        return false;
    }

    std::cout << "Waiting for service to start..." << std::endl;
    while (QueryServiceStatus(service_handle, &service_status) && service_status.dwCurrentState == SERVICE_START_PENDING)
    {
        Sleep(1000);
    }

    if (service_status.dwCurrentState == SERVICE_RUNNING)
    {
        std::cout << "Service started successfully" << std::endl;
        return true;
    }
    else
    {
        std::cerr << "Failed to start service: " << GetLastError() << std::endl;
        return false;
    }
}


bool service_utils::stop_service(SC_HANDLE service_handle)
{
    SC_HANDLE sc_manager_handle = open_sc_manager();

    CHECK_SC_MANAGER_HANDLE(sc_manager_handle, false);

    SERVICE_STATUS service_status;

    if (!ControlService(service_handle, SERVICE_CONTROL_STOP, &service_status))
    {
        CloseServiceHandle(sc_manager_handle);
        return false;
    }

    CloseServiceHandle(sc_manager_handle);

    return true;
}

const std::string DRIVER_NAME = "driver141";
const std::string DRIVER_FILE_NAME = "cpuzdriver.sys";

class Driver {
public:
  bool Load() {
    if (StopAndDeleteService()) {
      std::cout << "Service stopped and deleted successfully\n";
    }

    if (!CreateDriverFile()) {
      std::cerr << "Failed to create driver file\n";
      return false;
    }

    if (CreateAndStartService()) {
      std::cout << "Driver loaded successfully\n";
      return true;
    }
    else {
      std::cerr << "Failed to create and start service\n";
      return false;
    }
  }

private:
  std::unique_ptr<void, decltype(&CloseHandle)> serviceHandle_ = {nullptr, &CloseHandle};

  bool StopAndDeleteService() {
    SC_HANDLE service = OpenService(nullptr, DRIVER_NAME.c_str(), SERVICE_STOP | SERVICE_QUERY_STATUS | DELETE);
    if (!service) {
      // Service doesn't exist, so nothing to stop or delete
      return true;
    }

    SERVICE_STATUS status = {};
    if (ControlService(service, SERVICE_CONTROL_STOP, &status)) {
      std::cout << "Stopping service...\n";
      Sleep(1000); // Wait for service to stop
    }

    if (DeleteService(service)) {
      std::cout << "Service deleted successfully\n";
      CloseServiceHandle(service);
      return true;
    }
    else {
      std::cerr << "Failed to delete service: " << GetLastError() << '\n';
      CloseServiceHandle(service);
      return false;
    }
  }

  bool CreateDriverFile() {
    if (GetFileAttributesA(DRIVER_FILE_NAME.c_str()) != INVALID_FILE_ATTRIBUTES) {
      std::cout << "Driver file already exists\n";
      return true;
    }

    HANDLE file = CreateFileA(DRIVER_FILE_NAME.c_str(), GENERIC_WRITE, 0, nullptr, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, nullptr);
    if (file == INVALID_HANDLE_VALUE) {
      std::cerr << "Failed to create driver file: " << GetLastError() << '\n';
      return false;
    }


