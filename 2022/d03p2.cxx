#include <array>
#include <fstream>
#include <iostream>
#include <list>
#include <string>
#include <string_view>

auto main(int argc, char** argv) -> int
{
    if (argc != 2) {
        std::cerr << "invalid number of parameters" << std::endl;
        return 1;
    }

    std::ifstream input { argv[1] };
    if (!input.is_open()) {
        std::cerr << "failed to open" << std::endl;
        return 1;
    }

    std::size_t                sum = 0;
    std::array<std::string, 3> lines;

    while (std::getline(input, lines[0]) && std::getline(input, lines[1]) && std::getline(input, lines[2])) {
        for (auto chr : lines[0]) {
            if (lines[1].find(chr) != std::string_view::npos && lines[2].find(chr) != std::string_view::npos) {
                sum += (chr >= 'a' && chr <= 'z') ? (chr - 'a' + 1) : (chr - 'A' + 27);
                break;
            }
        }
    }

    std::cout << sum << std::endl;
    return 0;
}
