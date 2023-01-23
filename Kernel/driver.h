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

_Function_class_(DRIVER_UNLOAD) void unload(const PDRIVER_OBJECT driver_object)
{
	try
	{
		if (global_driver_instance)
		{
			global_driver_instance->pre_destroy(driver_object);
			delete global_driver_instance;
		}
	}
	catch (std::exception& e)
	{
		debug_log("Destruction error occured: %s\n", e.what());
	}
	catch (...)
	{
		debug_log("Unknown destruction error occured. This should not happen!");
	}
}

extern "C" NTSTATUS DriverEntry(const PDRIVER_OBJECT driver_object, PUNICODE_STRING /*registry_path*/)
{
    NTSTATUS status = STATUS_SUCCESS;
    try
    {
        driver_object->DriverUnload = unload;
        global_driver_instance = new global_driver(driver_object);
    }
    catch (const std::exception& e)
    {
        KdPrint(("Error: %s\n", e.what()));
        status = STATUS_INTERNAL_ERROR;
    }
    catch (...)
    {
        KdPrint(("Unknown initialization error occured"));
        status = STATUS_INTERNAL_ERROR;
    }
    return status;
}

