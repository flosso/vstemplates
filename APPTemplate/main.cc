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

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR    lpCmdLine,
	_In_ int       nCmdShow)
{
    CloseHandle(CreateThread(nullptr, NULL, Initialize, nullptr, NULL, nullptr));
	return TRUE;
}