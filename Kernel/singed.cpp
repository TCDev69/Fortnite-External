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

void Init()
{
	AllocConsole();
	freopen("CONIN$", "r", stdin);
	freopen("CONOUT$", "w", stdout);
	VALORANT::Module = (uintptr_t)GetModuleHandleA(0);
	uintptr_t WorldKey = *(uintptr_t*)(VALORANT::Module + Offsets::Key);
	State StateKey = *(State*)(VALORANT::Module + Offsets::State);
	uintptr_t UWorldXOR = Decryption::Decrypt_UWorld(WorldKey, (uintptr_t*)&StateKey);
	UWorld* UWorldClass = Memory::ReadStub<UWorld*>(UWorldXOR);
	UGameInstance* GameInstance = Memory::ReadStub<UGameInstance*>((uintptr_t)UWorldClass + 0x1A0);
	ULocalPlayer* LocalPlayers = Memory::ReadStub<ULocalPlayer*>((uintptr_t)GameInstance + 0x40); //this is tarray but im paster lol
	ULocalPlayer* LocalPlayer = Memory::ReadStub<ULocalPlayer*>((uintptr_t)LocalPlayers); //
	APlayerController* LocalController = Memory::ReadStub<APlayerController*>((uintptr_t)LocalPlayer + 0x38);
	uintptr_t ViewportClient = Memory::ReadStub<uintptr_t>((uintptr_t)LocalPlayer + 0x78);
	Hook::VMT((void*)ViewportClient, PostRender, 0x68, (void**)&pRender);
}


