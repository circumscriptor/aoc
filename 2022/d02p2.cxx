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
        auto result = line[2] - 'X';

        //        A  B  C |      A  B  C
        //        1  2  3 |      1  2  3
        //     +--------- |   +---------
        //   1 |  0  1  2 | 1 |  0  1  2
        //   2 | -1  0  1 | 2 |  2  0  1
        //   3 | -2 -1  0 | 3 |  1  2  0

        sum += ((value1 + (result == 1 ? 2 : (result == 0 ? 1 : 0))) % 3) + 1 + result * 3;
    }

    std::cout << sum << std::endl;
    return 0;
}
