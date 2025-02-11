#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "balanced_checker.h"

int main() {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    int groupSize = 3; 
    int iterations = 100000;  
    int balancedCount = 0;

    for (int iter = 0; iter < iterations; ++iter) {
        std::vector<int> parensSequence = generateRandomParentheses(groupSize);
        if (isBalanced(parensSequence)) {
            balancedCount++;
        }
    }

    double balancedRatio = static_cast<double>(balancedCount) / iterations;

    std::cout << "Total iterations: " << iterations << std::endl;
    std::cout << "Balanced sequences count: " << balancedCount << std::endl;
    std::cout << "Ratio of balanced sequences: " << balancedRatio << std::endl;

    return 0;
}
