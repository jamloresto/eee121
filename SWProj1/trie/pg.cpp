#include "Trie.h"
#include <iostream>
using namespace std;

int main() {
    int testCases;
    cin >> testCases;
    while (testCases--) {
        int n;
        cin >> n;
        Trie trie;
        int totalDigits = 0;
        for (int i = 0; i < n; i++) {
            string binaryString;
            cin >> binaryString;
            totalDigits += binaryString.length();
            trie.insert(binaryString);
        }
        cout << "Total Digits: " << totalDigits << endl;
        cout << "Trie Node Count: " << trie.getNodeCount() << endl;
        cout << "Max Prefix Length: " << trie.getMaxPrefixLength() << endl;
        cout << "Total Substrings: " << trie.getTotalSubstrings() << endl;
        cout << "Prefix Goodness: " << trie.getPrefixGoodness() << endl;
    }
    return 0;
}
