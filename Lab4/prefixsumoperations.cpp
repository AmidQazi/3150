#include <iostream>
#include <vector>
#include <algorithm>
#include "prefixsumoperations.h"
#include <random>

void fisherYatesShuffle(std::vector<int>& sequence) {
    int n = sequence.size();
    for (int i = n - 1; i > 0; --i) {
        int j = std::rand() % (i + 1);
        std::swap(sequence[i], sequence[j]);
    }
}

std::vector<int> fillWithOnesAndNegOnes(int n) {
    std::vector<int> result;
    for (int i = 0; i < n; ++i) {
        result.push_back(1);
    }
    for (int i = 0; i < n; ++i) {
        result.push_back(-1);
    }
    result.push_back(-1); 
    return result;
}



std::vector<int> calculatePrefixSum(const std::vector<int>& array) {
    std::vector<int> result = array;
    for (int i = 1; i < result.size(); ++i) {
        result[i] += result[i - 1];
    }
    return result;
}

int findLowestPrefixSumIndex(const std::vector<int>& prefixSum) {
    int minIndex = 0;
    int minValue = prefixSum[0];
    for (size_t i = 1; i < prefixSum.size(); ++i) {
        if (prefixSum[i] < minValue) {
            minValue = prefixSum[i];
            minIndex = i;
        }
    }
    return minIndex;
}


std::pair<std::vector<int>, std::vector<int>> splitAtIndex(const std::vector<int>& array, int index) {
    std::vector<int> p1(array.begin(), array.begin() + index + 1);
    std::vector<int> p2(array.begin() + index + 1, array.end());
    return {p1, p2};
}

void p1p2(std::vector<int>& p1, std::vector<int>& p2) {
    if (p1.back() != -1) {
        p1.pop_back();
        p2.insert(p2.begin(), 1);
    }
}

std::vector<int> concatenateArrays(const std::vector<int>& p1, const std::vector<int>& p2) {
    std::vector<int> result;
    result.reserve(p1.size() + p2.size());
    result.insert(result.end(), p1.begin(), p1.end());
    result.insert(result.end(), p2.begin(), p2.end());
    return result;
}

std::vector<int> createNonCrossingPrefixSum(int n) {
    std::vector<int> array = fillWithOnesAndNegOnes(n);

    fisherYatesShuffle(array);

    std::vector<int> prefixSum = calculatePrefixSum(array);
    int minDepthIndex = findLowestPrefixSumIndex(prefixSum);
    std::vector<int> p1, p2;
    auto splitResult = splitAtIndex(array, minDepthIndex);
    p1 = splitResult.first;
    p2 = splitResult.second;

    p1p2(p1, p2);
    p1.pop_back(); 
    std::vector<int> concatenatedPrefixSum = calculatePrefixSum(concatenateArrays(p2, p1));
    return concatenatedPrefixSum;
}
