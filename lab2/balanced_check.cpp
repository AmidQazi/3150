#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "balanced_check.h" // Updated to reflect the new header file name
#include <random>

void exchangeValues(int* x, int* y) {
    int hold = *x;
    *x = *y;
    *y = hold;
}

void applyShuffle(std::vector<int>& vec) {
    int length = vec.size();
    for (int i = length - 1; i > 0; --i) {
        int j = std::rand() % (i + 1);
        std::swap(vec[i], vec[j]);
    }
}

void displayVector(const std::vector<int>& vec) {
    for (int val : vec) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
}

bool isSequenceBalanced(const std::vector<int>& seq) {
    int balance = 0;
    for (int val : seq) {
        balance += val;
        if (balance < 0) {
            return false;
        }
    }
    return balance == 0;
}

std::vector<int> createBalancedSequence(int count) {
    std::vector<int> vec(2 * count, 0);
    for (int i = 0; i < count; ++i) {
        vec[i] = 1;       
        vec[i + count] = -1;  
    }

    applyShuffle(vec);
    return vec;
}
