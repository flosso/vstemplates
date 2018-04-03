#include <Windows.h>
#include <string>
#include <iostream>
#include <thread>

void Initialize()
{
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
}

void Uninitialize()
{
}

void PrintHelpInfo()
{
    std::cout << u8"Commands:" << std::endl;
    std::cout << u8"0. help" << std::endl;
    std::cout << u8"1. inject" << std::endl;
    std::cout << u8"2. enject" << std::endl;
    std::cout << u8"8. quit" << std::endl;
}

bool CommandHandler(std::string& line)
{
    if (line.empty()) {
    } else if (line == "8" || line == "quit") {
        return true;
    } else if (line == "0" || line == "help" || line == "?") {
        PrintHelpInfo();
    } else if (line == "1") {

    } else if (line == "2") {

    } else if (line.substr(0, 4) == "echo") {
        std::cout << line.substr(5) << std::endl;
    } else {
        std::cout << line << std::endl;
    }
    std::cout << "Enter:";
    return false;
}

int main(int argc, char* argv[])
{
    try {
        Initialize();
        std::string line;
        PrintHelpInfo();
        std::cout << "Enter:";
        while (std::getline(std::cin, line)) {
            if (CommandHandler(line))
                break;
        }
        Uninitialize();
        return 0;
    } catch (std::exception& e) {
        std::cout << "[main] exception:" << e.what() << std::endl;
        return 1;
    }
}
