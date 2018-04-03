#include <string>
#include <fstream>

std::string read_file(const std::wstring& filename)
{
    std::string content;
    std::ifstream file(filename, std::ios::in | std::ios::binary | std::ios::ate);
    if (file.is_open()) {
        size_t size = static_cast<size_t>(file.tellg());
        if (size) {
            file.seekg(0, std::ios::beg);
            content.reserve(size);
            content.assign(std::istreambuf_iterator<char>(file), std::istreambuf_iterator<char>());
        }
        file.close();
    }
    return content;
}

bool write_file(const std::wstring& filename, const std::string& data, bool append = false)
{
    std::ofstream file(filename, append ? std::ios::app | std::ios::binary : std::ios::out | std::ios::binary | std::ios::trunc);
    if (file.is_open()) {
        file.write(data.c_str(), data.size());
        file.close();
        return true;
    }
    return false;
}

int wmain(int argc, wchar_t* argv[])
{
    try {
        if (argc < 2)
            return 1;
        std::wstring file = argv[1];
        auto data = read_file(file);
        if(data.empty())
            return 2;
        auto begin = data.find("<ProjectGuid>");
        if (begin == std::string::npos)
            return 3;
        begin = begin + 13;
        auto end = data.find("</ProjectGuid>", begin);
        if (end == std::string::npos)
            return 4;
        data.replace(begin, end - begin, "{$guid1$}");
        if (!write_file(file, data))
            return 5;
        return 0;
    } catch (std::exception& e) {
        printf_s("[main] exception: %s", e.what());
        return -1;
    }
}
