#ifndef TRIE_H
#define TRIE_H
#include "TrieNode.h"
#include <string>

class Trie {
private:
    TrieNode* root;
    int countSubstrings(TrieNode* node, int depth = 0);
    void clear(TrieNode* node);
    int countNodes(TrieNode* node);

public:
    Trie();
    ~Trie();
    void insert(const std::string& binaryString);
    bool search(const std::string& binaryString);
    int getNodeCount();
    int getMaxPrefixLength();
    int getTotalSubstrings();
    int getPrefixGoodness();
};

#endif // TRIE_H