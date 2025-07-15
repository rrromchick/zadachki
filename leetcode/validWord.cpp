#include <string>
#include <vector>
#include <algorithm>

class Solution {
public:
    bool isValid(std::string word) {
        std::vector<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        if (word.length() < 3) return false;
        bool vowel = false, consonant = false;
        for (int i = 0; i < word.length(); ++i) {
            if (!std::isdigit(word[i]) && !std::isalpha(word[i])) return false;
            if (std::isalpha(word[i]) && std::find(vowels.begin(), vowels.end(), std::tolower(word[i])) == vowels.end()) {
                consonant = true;
            } else if (std::isalpha(word[i])) {
                vowel = true;
            }
        }

        return (vowel && consonant);
    }
};