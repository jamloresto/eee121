#ifndef MORSETRIE_H
#define MORSETRIE_H

#include <unordered_map>
#include <string>

class MorseTrie {
private:
    std::unordered_map<std::string, char> morseToChar;
    std::unordered_map<char, std::string> charToMorse;

public:
    MorseTrie();
    std::string encode(const std::string &text);
    std::string decode(const std::string &morse);
};

#endif
