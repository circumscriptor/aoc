#include <array>
#include <fstream>
#include <iostream>
#include <set>
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

    std::size_t                sum = 0;
    std::multiset<std::size_t> all {};
    std::string                line;
    while (std::getline(input, line)) {
        if (line.empty()) {
            all.insert(sum);
            sum = 0;
            continue;
        }
        sum += std::stoul(line);
    }

    auto        iterator = all.rbegin();
    std::size_t max      = *iterator + *(++iterator) + *(++iterator);
    std::cout << max << std::endl;
    return 0;
}
