#include <array>
#include <fstream>
#include <iostream>
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

    std::size_t sum = 0;
    std::string line;
    while (std::getline(input, line)) {
        const auto half = line.length() / 2;

        std::string_view view = line;

        auto first  = view.substr(0, half);
        auto second = view.substr(half, half);

        for (auto chr : first) {
            if (second.find(chr) != std::string_view::npos) {
                sum += (chr >= 'a' && chr <= 'z') ? (chr - 'a' + 1) : (chr - 'A' + 27);
                break;
            }
        }
    }

    std::cout << sum << std::endl;
    return 0;
}
