#include <array>
#include <cmath>
#include <fstream>
#include <iostream>
#include <string>

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
        if (line.empty()) {
            continue;
        }

        auto value1 = line[0] - 'A' + 1;
        auto value2 = line[2] - 'X' + 1;

        //        A  B  C
        //        1  2  3
        //     +---------
        // X 1 |  0  1  2
        // Y 2 | -1  0  1
        // Z 3 | -2 -1  0
        auto diff = value1 < value2 ? value1 - value2 + 3 : value1 - value2;
        sum       += value2 + (diff == 2 ? 6 : (diff == 0 ? 3 : 0));
    }

    std::cout << sum << std::endl;
    return 0;
}
