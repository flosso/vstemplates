#include <Windows.h>
#include <cstdio>

void Initialize()
{
	AllocConsole();
	FILE *stream;
	freopen_s(&stream, "CONIN$", "r+t", stdin);
	freopen_s(&stream, "CONOUT$", "w+t", stdout);
	ShowWindow(GetConsoleWindow(), SW_SHOW);
	system("pause");
}

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR    lpCmdLine,
	_In_ int       nCmdShow)
{
	//CreateThread(nullptr, NULL, reinterpret_cast<LPTHREAD_START_ROUTINE>(Initialize), nullptr, NULL, nullptr);
	Initialize();
	return TRUE;
}