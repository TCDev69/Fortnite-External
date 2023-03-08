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
            sleepNotification(type);
        };

        // Output message to debug log
        DebugLog("Driver started");

        // Initialize the hypervisor
        hypervisor_.initialize();
    }

    ~GlobalDriver()
    {
        // Output message to debug log
        DebugLog("Unloading driver");

        // Disable all EPT hooks
        hypervisor_.disableAllEptHooks();

        // Cleanup the hypervisor
        hypervisor_.cleanup();
    }

    // Disallow copy and move construction/assignment
    GlobalDriver(const GlobalDriver&) = delete;
    GlobalDriver& operator=(const GlobalDriver&) = delete;
    GlobalDriver(GlobalDriver&&) = delete;
    GlobalDriver& operator=(GlobalDriver&&) = delete;

    void preDestroy(const PDRIVER_OBJECT /*driverObject*/)
    {
        // Perform any necessary cleanup before the driver is unloaded
    }

private:
    bool hypervisor_was_enabled_ = false;
    Hypervisor hypervisor_;
    SleepCallback sleepCallback_;
    Irp irp_;

    void sleepNotification(const SleepCallback::Type type)
    {
        if (type == SleepCallback::Type::Sleep)
        {
            DebugLog("Going to sleep...\n");

            // Save the previous hypervisor state before disabling it
            hypervisor_was_enabled_ = hypervisor_.isEnabled();
            hypervisor_.disable();
        }
        else if (type == SleepCallback::Type::Wakeup && hypervisor_was_enabled_)
        {
            DebugLog("Waking up...\n");

            // Restore the previous hypervisor state
            hypervisor_.enable();
        }
    }
};

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
        else
        {
            // If global_driver_instance is null, there is nothing to unload.
            // This may indicate an error in the driver initialization process.
            printf("Error: global_driver_instance is null.\n");
        }
    }
    catch (const std::exception& e)
    {
        // If an exception is caught, log the error and attempt to clean up
        printf("Destruction error occurred: %s\n", e.what());
        global_driver_instance = nullptr;
    }
    catch (...)
    {
        // If an unknown exception is caught, log the error and attempt to clean up
        printf("Unknown destruction error occurred. This should not happen!\n");
        global_driver_instance = nullptr;
    }
}

extern "C" NTSTATUS DriverEntry(PDRIVER_OBJECT driver_object, PUNICODE_STRING registry_path)
{
    NTSTATUS status = STATUS_SUCCESS;
    global_driver* driver_instance = nullptr;

    try
    {
        // Set the DriverUnload function pointer to the unload function
        driver_object->DriverUnload = unload;

        // Create a global driver instance
        driver_instance = new global_driver(driver_object);

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

    if (status != STATUS_SUCCESS)
    {
        // If an error occurred, clean up the driver instance if it was created
        if (driver_instance != nullptr)
        {
            delete driver_instance;
            driver_instance = nullptr;
        }
    }

    // Return the status code
    return status;
}

