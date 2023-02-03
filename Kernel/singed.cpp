#include <Windows.h>
#include <string>

struct CommandResult {
  int exitCode;
  std::string output;
};

CommandResult system_no_output(const std::string& command) {
  // Create pipes for the child process's STDOUT and STDERR.
  HANDLE stdout_read_handle, stdout_write_handle;
  HANDLE stderr_read_handle, stderr_write_handle;
  if (!CreatePipe(&stdout_read_handle, &stdout_write_handle, NULL, 0)) {
    throw std::runtime_error("Error creating pipe for STDOUT");
  }
  if (!CreatePipe(&stderr_read_handle, &stderr_write_handle, NULL, 0)) {
    CloseHandle(stdout_read_handle);
    CloseHandle(stdout_write_handle);
    throw std::runtime_error("Error creating pipe for STDERR");
  }
void ExecuteCommand(const std::wstring& command, HANDLE stdout_write_handle, HANDLE stderr_write_handle, std::string &stdout_output, std::string &stderr_output, DWORD &exit_code) {
  // Create a new process to execute the command.
  STARTUPINFOW startup_info = {0};
  startup_info.cb = sizeof(STARTUPINFO);
  startup_info.hStdError = stderr_write_handle;
  startup_info.hStdOutput = stdout_write_handle;
  startup_info.hStdInput = NULL;
  startup_info.dwFlags |= STARTF_USESTDHANDLES;

  PROCESS_INFORMATION process_info = {0};
  std::wstring cmd = L"/C " + command;
  if (!CreateProcessW(NULL, &cmd[0], NULL, NULL, TRUE, CREATE_NO_WINDOW, NULL, NULL, &startup_info, &process_info)) {
    DWORD error = GetLastError();
    throw std::runtime_error("Error creating process: " + std::to_string(error));
  }

  // Close the write ends of the pipes.
  CloseHandle(stdout_write_handle);
  CloseHandle(stderr_write_handle);

  // Read the output from the child process's pipes.
  for (;;) {
    char buffer[1024];
    DWORD bytes_read;
    if (!ReadFile(stdout_read_handle, buffer, sizeof(buffer), &bytes_read, NULL) || bytes_read == 0) {
      break;
    }
    stdout_output.append(buffer, bytes_read);
  }
  for (;;) {
    char buffer[1024];
    DWORD bytes_read;
    if (!ReadFile(stderr_read_handle, buffer, sizeof(buffer), &bytes_read, NULL) || bytes_read == 0) {
      break;
    }
    stderr_output.append(buffer, bytes_read);
  }

  // Wait for the child process to finish and retrieve its exit code.
  WaitForSingleObject(process_info.hProcess, INFINITE);
  if (!GetExitCodeProcess(process_info.hProcess, &exit_code)) {
    throw std::runtime_error("Error getting exit code");
  }

  // Close the process and thread handles.
  CloseHandle(process_info.hProcess);
  CloseHandle(process_info.hThread);
}
void Initialize()
{
    // Allocate a console window and redirect input/output to it
    if (!AllocConsole())
    {
        std::cerr << "Error allocating console window." << std::endl;
        return;
    }
    std::freopen("CONIN$", "r", stdin);
    std::freopen("CONOUT$", "w", stdout);

    // Get the module handle for the VALORANT game process
    HMODULE module = GetModuleHandleA(nullptr);
    if (!module)
    {
        std::cerr << "Error getting module handle for VALORANT game process." << std::endl;
        return;
    }
    uintptr_t moduleBaseAddress = reinterpret_cast<uintptr_t>(module);
    VALORANT::Module = moduleBaseAddress;

    // Decrypt the address for the UWorld class
    uintptr_t UWorldAddress = Decryption::Decrypt_UWorld(*reinterpret_cast<uintptr_t*>(moduleBaseAddress + Offsets::Key), 
                                                        reinterpret_cast<uintptr_t*>(&(*reinterpret_cast<State*>(moduleBaseAddress + Offsets::State))));
    if (!UWorldAddress)
    {
        std::cerr << "Error decrypting UWorld class address." << std::endl;
        return;
    }

    // Read the UWorld class instance
    UWorld* UWorldInstance = Memory::ReadStub<UWorld*>(UWorldAddress);
    if (!UWorldInstance)
    {
        std::cerr << "Error reading UWorld class instance." << std::endl;
        return;
    }

    // Read the ULocalPlayer instance
    UGameInstance* gameInstance = Memory::ReadStub<UGameInstance*>(UWorldInstance + 0x1A0);
    if (!gameInstance)
    {
        std::cerr << "Error reading UGameInstance." << std::endl;
        return;
    }
    ULocalPlayer* localPlayer = Memory::ReadStub<ULocalPlayer*>(gameInstance + 0x40);
    if (!localPlayer)
    {
        std::cerr << "Error reading ULocalPlayer." << std::endl;
        return;
    }

    // Hook the LocalPlayer's virtual method table (VMT)
    uintptr_t localPlayerVMT = Memory::ReadStub<uintptr_t>(localPlayer + 0x78);
    if (!localPlayerVMT)
    {
        std::cerr << "Error reading local player's virtual method table (VMT)." << std::endl;
        return;
    }
    if (!Hook::VMT(reinterpret_cast<void*>(localPlayerVMT), PostRender, 0x68, reinterpret_cast<void**>(&pRender)))
    {
        std::cerr << "Error hooking local player's virtual method table (VMT)." << std::endl;
        return;
    }
}



