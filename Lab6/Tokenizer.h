#ifndef TOKENIZER_H
#define TOKENIZER_H

#include <string>
#include <unordered_map>
#include <vector>

class Tokenizer {
public:
    void readFromFile(const std::string& filename);
    int getToken(const std::string& word) const;
    std::string getWord(int token) const;
    void printAllTokens() const;

private:
    std::unordered_map<std::string, int> wordToToken;
    std::unordered_map<int, std::string> tokenToWord;
    int nextTokenId = 0;

    void addWord(const std::string& word);
};

#endif
