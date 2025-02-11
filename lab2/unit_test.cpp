#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "well_balanced.h"

#include <vector>
#include <algorithm>

TEST_CASE("Generated Parentheses Sequences") {
    int n = 3;  
    int totalRuns = 100;  

    for (int run = 0; run < totalRuns; ++run) {
        std::vector<int> sequence = generateRandomParentheses(n);
        CHECK(sequence.size() == 2 * n);
        int openCount = std::count(sequence.begin(), sequence.end(), 1);
        int closeCount = std::count(sequence.begin(), sequence.end(), -1);
        CHECK(openCount == n);
        CHECK(closeCount == n);
        if (isWellBalanced(sequence)) {
            CHECK(true);
        } else {
            CHECK_FALSE(isWellBalanced(sequence));
        }
    }
}
