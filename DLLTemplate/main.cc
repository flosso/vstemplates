#include <Windows.h>
#include <cstdio>
#include <clocale>

FILE* con_in = nullptr;
FILE* con_out = nullptr;

void EnableConsole()
{
    AllocConsole();
    freopen_s(&con_in, "CONIN$", "r+t", stdin);
    freopen_s(&con_out, "CONOUT$", "w+t", stdout);
    SetConsoleCP(936);
    SetConsoleOutputCP(936);
    setlocale(LC_CTYPE, "");

    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_FONT_INFOEX cfi;
    cfi.cbSize = sizeof(cfi);
    cfi.nFont = 0;
    cfi.dwFontSize.X = 8;
    cfi.dwFontSize.Y = 16;
    cfi.FontFamily = 54;
    cfi.FontWeight = 400;
    wcscpy_s(cfi.FaceName, L"ÐÂËÎÌå");
    SetCurrentConsoleFontEx(out, false, &cfi);
    SetConsoleScreenBufferSize(out, { 120, 3000 });
    SMALL_RECT sr{ 0, 0, 120, 30 };
    SetConsoleWindowInfo(out, FALSE, &sr);
    ShowWindow(GetConsoleWindow(), SW_SHOW);
}

DWORD WINAPI Initialize(LPVOID lpArguments)
{
#ifdef _DEBUG
    EnableConsole();
#endif
	
    return 0;
}

void UnInitialize()
{
#ifdef _DEBUG
    if (con_in)
        fclose(con_in);
    if (con_out)
        fclose(con_out);
    FreeConsole();
#endif
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