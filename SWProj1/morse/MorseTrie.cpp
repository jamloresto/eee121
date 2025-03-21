#include "MorseTrie.h"
#include <sstream>
#include <cctype>

// Constructor: Initializes Morse code mappings
MorseTrie::MorseTrie() {
    morseToChar = {
        {".-", 'A'},   {"-...", 'B'}, {"-.-.", 'C'}, {"-..", 'D'},  {".", 'E'},
        {"..-.", 'F'}, {"--.", 'G'},  {"....", 'H'}, {"..", 'I'},   {".---", 'J'},
        {"-.-", 'K'},  {".-..", 'L'}, {"--", 'M'},   {"-.", 'N'},   {"---", 'O'},
        {".--.", 'P'}, {"--.-", 'Q'}, {".-.", 'R'},  {"...", 'S'},  {"-", 'T'},
        {"..-", 'U'},  {"...-", 'V'}, {".--", 'W'},  {"-..-", 'X'}, {"-.--", 'Y'},
        {"--..", 'Z'}, {"-----", '0'}, {".----", '1'}, {"..---", '2'}, {"...--", '3'},
        {"....-", '4'}, {".....", '5'}, {"-....", '6'}, {"--...", '7'}, {"---..", '8'},
        {"----.", '9'}, {"/", ' '}
    };

    for (const auto &pair : morseToChar) {
        charToMorse[pair.second] = pair.first;
    }
}

// Encode text into Morse code
std::string MorseTrie::encode(const std::string &text) {
    std::string result;
    for (char c : text) {
        if (std::isalpha(c) || std::isdigit(c)) {
            result += charToMorse[toupper(c)] + " ";
        } else if (c == ' ') {
            result += "/ ";  // Space is represented as '/'
        }
    }
    return result.empty() ? "" : result.substr(0, result.length() - 1);  // Trim last space
}

// Decode Morse code into text
std::string MorseTrie::decode(const std::string &morse) {
    std::string result, segment;
    std::stringstream ss(morse);
    
    while (ss >> segment) {
        result += morseToChar.count(segment) ? morseToChar[segment] : '?';
    }

    return result;
}
