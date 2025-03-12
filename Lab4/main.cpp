#include <iostream>
#include "prefixsumoperations.h"
#include <cstdlib>
#include <ctime>

int main() {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    int n;

    std::cout << "Enter the size of the array: ";
    std::cin >> n;

    std::vector<int> result = createNonCrossingPrefixSum(n);
    std::cout << "Non-crossing Prefix Sum Array: ";
    for (size_t i = 0; i < result.size(); ++i) {
        std::cout << result[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
