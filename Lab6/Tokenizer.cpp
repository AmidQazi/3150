#include "Tokenizer.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <cctype>

void Tokenizer::readFromFile(const std::string& filename) {
    std::ifstream file(filename);
    std::string word;

    if (!file) {
        throw std::runtime_error("Failed to open file: " + filename);
    }

    while (file >> word) {
        // Clean punctuation
        word.erase(remove_if(word.begin(), word.end(), ::ispunct), word.end());
        addWord(word);
    }
}

void Tokenizer::addWord(const std::string& word) {
    if (wordToToken.find(word) == wordToToken.end()) {
        wordToToken[word] = nextTokenId;
        tokenToWord[nextTokenId] = word;
        nextTokenId++;
    }
}

int Tokenizer::getToken(const std::string& word) const {
    auto it = wordToToken.find(word);
    if (it != wordToToken.end()) {
        return it->second;
    }
    throw std::runtime_error("Word not found: " + word);
}

std::string Tokenizer::getWord(int token) const {
    auto it = tokenToWord.find(token);
    if (it != tokenToWord.end()) {
        return it->second;
    }
    throw std::runtime_error("Token not found: " + std::to_string(token));
}

void Tokenizer::printAllTokens() const {
    for (const auto& pair : wordToToken) {
        std::cout << pair.first << " => " << pair.second << "\n";
    }
}
