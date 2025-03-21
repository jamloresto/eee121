#include "MorseTrie.h"
#include <iostream>
#include <cctype>
using namespace std;

int main() {
    MorseTrie morseTrie;
    string input;
    getline(cin, input);  

    // Check if the input contains alphanumeric characters (meaning it should be encoded)
    bool isAlphanumeric = false;
    for (char c : input) {
        if (isalnum(c)) {
            isAlphanumeric = true;
            break;
        }
    }

    if (isAlphanumeric) {
        cout << "Encoded: " << morseTrie.encode(input) << endl;
    } else {
        cout << "Decoded: " << morseTrie.decode(input) << endl;
    }

    return 0;
}
