#include "std_include.hpp"
#include "logging.hpp"
#include "sleep_callback.hpp"
#include "irp.hpp"
#include "exception.hpp"
#include "hypervisor.hpp"

#define DOS_DEV_NAME L"\\DosDevices\\HelloDev"
#define DEV_NAME L"\\Device\\HelloDev"

class GlobalDriver
{
public:
    GlobalDriver(const PDRIVER_OBJECT driverObject)
        : irp_(driverObject, DEV_NAME, DOS_DEV_NAME)
    {
        // Initialize the sleep callback
        sleepCallback_ = [this](const SleepCallback::Type type)
        {
            this->sleepNotification(type);
        };

        // Output message to debug log
        DebugLog("Driver started");
    }

    ~GlobalDriver()
    {
        // Output message to debug log
        DebugLog("Unloading driver");

        // Disable all EPT hooks
        hypervisor_.disableAllEptHooks();
    }

    GlobalDriver(GlobalDriver&&) = delete;
    GlobalDriver& operator=(GlobalDriver&&) = delete;

    GlobalDriver(const GlobalDriver&) = delete;
    GlobalDriver& operator=(const GlobalDriver&) = delete;

    void preDestroy(const PDRIVER_OBJECT /*driverObject*/)
    {
        // Perform any necessary cleanup before the driver is unloaded
    }

private:
    bool hypervisor_was_enabled_ = false;  // initialize to false by default
    Hypervisor hypervisor_;
    SleepCallback sleep_callback_;
    Irp irp_;

public:
    void SleepNotification(const SleepCallback::Type type)
    {
        if (type == SleepCallback::Type::Sleep)
        {
            DebugLog("Going to sleep...\n");
            this->hypervisor_was_enabled_ = this->hypervisor_.IsEnabled();
            this->hypervisor_.Disable();
        }

        if (type == SleepCallback::Type::Wakeup && this->hypervisor_was_enabled_)
        {
            DebugLog("Waking up...\n");
            this->hypervisor_.Enable();
        }
    }
};
global_driver* global_driver_instance{nullptr};

class global_driver
{
public:
    global_driver(PDRIVER_OBJECT driver_object)
    {
        // Perform driver-specific initialization here.
    }

    ~global_driver()
    {
        // Perform driver-specific cleanup here.
    }

    void pre_destroy(PDRIVER_OBJECT driver_object)
    {
        // Perform any necessary cleanup before destroying the instance.
    }
};

global_driver* global_driver_instance = nullptr;

void unload(PDRIVER_OBJECT driver_object)
{
    try
    {
        if (global_driver_instance)
        {
            global_driver_instance->pre_destroy(driver_object);
            delete global_driver_instance;
            global_driver_instance = nullptr;
        }
    }
    catch (const std::exception& e)
    {
        printf("Destruction error occurred: %s\n", e.what());
    }
    catch (...)
    {
        printf("Unknown destruction error occurred. This should not happen!\n");
    }
}

extern "C" NTSTATUS DriverEntry(PDRIVER_OBJECT driver_object, PUNICODE_STRING registry_path)
{
    NTSTATUS status = STATUS_SUCCESS;

    try
    {
        // Set the DriverUnload function pointer to the unload function
        driver_object->DriverUnload = unload;

        // Create a global driver instance
        global_driver_instance = new global_driver(driver_object);

        // Log the driver initialization message
        DbgPrint("Driver initialized successfully\n");
    }
    catch (const std::exception& e)
    {
        // Log the error message and set the status code to indicate an error
        DbgPrint("Error initializing driver: %s\n", e.what());
        status = STATUS_INTERNAL_ERROR;
    }
    catch (...)
    {
        // Log the error message and set the status code to indicate an error
        DbgPrint("Unknown initialization error occurred\n");
        status = STATUS_INTERNAL_ERROR;
    }

    // Return the status code
    return status;
}
