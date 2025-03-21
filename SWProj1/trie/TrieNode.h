#ifndef TRIENODE_H
#define TRIENODE_H
#include <unordered_map>

class TrieNode {
public:
    char character;
    bool is_end_of_word;
    std::unordered_map<char, TrieNode*> children;

    TrieNode(char c = '\0');
};

#endif // TRIENODE_H