#include <Windows.h>
#include <cstdio>

DWORD WINAPI Initialize(LPVOID lpArguments)
{
	AllocConsole();
	FILE *stream;
	freopen_s(&stream, "CONIN$", "r+t", stdin);
	freopen_s(&stream, "CONOUT$", "w+t", stdout);
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
	ShowWindow(GetConsoleWindow(), SW_SHOW);
	
    return 0;
}

void UnInitialize()
{
    FreeConsole();
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD  dwReason, LPVOID lpReserved)
{
	switch (dwReason)
	{
	case DLL_PROCESS_ATTACH:
		DisableThreadLibraryCalls(hModule);
        CloseHandle(CreateThread(nullptr, NULL, Initialize, nullptr, NULL, nullptr));
		break;
	case DLL_PROCESS_DETACH:
        UnInitialize();
		break;
	default:
		break;
	}
	return TRUE;
}