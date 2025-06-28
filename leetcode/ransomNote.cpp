#include <string>
#include <unordered_map>

class Solution {
public:
    bool canConstruct(std::string ransomNote, std::string magazine) {
        int n = ransomNote.length();
        int m = magazine.length();
        std::unordered_map<char, int> f, s;

        for (const auto& ch : ransomNote) {
            ++f[ch];
        }
        for (const auto& ch : magazine) {
            ++s[ch];
        }

        for (const auto& [ch, cnt] : f) {
            if (cnt > s[ch]) {
                return false;
            }
        }

        return true;
    }
};