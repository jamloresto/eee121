#include "Trie.h"
#include <iostream>

Trie::Trie() { root = new TrieNode(); }

Trie::~Trie() { clear(root); }

void Trie::clear(TrieNode* node) {
    if (!node) return;
    for (auto& child : node->children)
        clear(child.second);
    delete node;
}

void Trie::insert(const std::string& binaryString) {
    TrieNode* node = root;
    for (char bit : binaryString) {
        if (node->children.find(bit) == node->children.end())
            node->children[bit] = new TrieNode(bit);
        node = node->children[bit];
    }
    node->is_end_of_word = true;
}

bool Trie::search(const std::string& binaryString) {
    TrieNode* node = root;
    for (char bit : binaryString) {
        if (node->children.find(bit) == node->children.end())
            return false;
        node = node->children[bit];
    }
    return node->is_end_of_word;
}

int Trie::getNodeCount() {
    return countNodes(root);
}

int Trie::countNodes(TrieNode* node) {
    if (!node) return 0;
    int count = 1;
    for (auto& child : node->children)
        count += countNodes(child.second);
    return count;
}

int Trie::getMaxPrefixLength() { // i can't get the right answer here
    TrieNode* node = root;
    int maxLength = 0;

    while (node && node->children.size() == 1 && !node->is_end_of_word) {
        node = node->children.begin()->second;
        maxLength++;
    }

    return maxLength;
}


int Trie::getTotalSubstrings() { // i can't get the right answer here
    return countSubstrings(root);
}

int Trie::countSubstrings(TrieNode* node, int depth) {
    if (!node) return 0;
    int count = depth;
    for (auto& child : node->children)
        count += countSubstrings(child.second, depth + 1);
    return count;
}

int Trie::getPrefixGoodness() { // i can't get the right answer here because the maxprefixelength and total substrings are wrong
    return getMaxPrefixLength() * getTotalSubstrings();
}