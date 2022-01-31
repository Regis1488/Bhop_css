#include <Windows.h>
#include <iostream>
DWORD pid;
DWORD BunnyHop = 0x0CD79A54;
DWORD ForceJump = 0x5F705D24;
int value;
int fj;


int main()
{
	HWND hWnd = FindWindowA(0, ("Counter-Strike Source"));
	GetWindowThreadProcessId(hWnd, &pid);
	HANDLE pHandle = OpenProcess(PROCESS_ALL_ACCESS, FALSE , pid);
	for (;;) {
		ReadProcessMemory(pHandle, (void*)BunnyHop, &value, sizeof(value), 0);
		if (GetAsyncKeyState(VK_SPACE) && value == 257) {
			fj = 5;
			WriteProcessMemory(pHandle, (LPVOID)ForceJump, &fj, sizeof(int), 0);
			
		}
		else {
			fj = 4;
			WriteProcessMemory(pHandle, (LPVOID)ForceJump, &fj, sizeof(int), 0);
		}
	}
}