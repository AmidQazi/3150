#ifndef __BALANCED_CHECK_H
#define __BALANCED_CHECK_H

#include <vector>

// Check if the sequence is balanced.
bool isSequenceBalanced(const std::vector<int>& seq);

// Generate a random sequence of balanced parentheses.
std::vector<int> createBalancedSequence(int count);

// Apply Fisher-Yates shuffle to the vector.
void applyShuffle(std::vector<int>& vec);

// Swap two integer values.
void exchangeValues(int* x, int* y);

// Display elements of the vector.
void displayVector(const std::vector<int>& vec);

#endif
