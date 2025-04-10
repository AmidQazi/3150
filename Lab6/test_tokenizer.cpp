#include "Tokenizer.h"
#include <cassert>
#include <iostream>
#include <fstream>

void createSampleFile(const std::string& filename) {
    std::ofstream file(filename);
    file << "hello world hello test";
}

void runTests() {
    Tokenizer tokenizer;

    createSampleFile("sample.txt");
    tokenizer.readFromFile("sample.txt");

    assert(tokenizer.getToken("hello") == 0);
    assert(tokenizer.getToken("world") == 1);
    assert(tokenizer.getToken("test") == 2);

    assert(tokenizer.getWord(0) == "hello");
    assert(tokenizer.getWord(1) == "world");
    assert(tokenizer.getWord(2) == "test");

    std::cout << "All tests passed!\n";
}

int main() {
    runTests();
    return 0;
}
