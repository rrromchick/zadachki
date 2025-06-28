#include <unordered_map>
#include <string>

class Solution {
public:
    bool isAnagram(std::string s, std::string t) {
        if (s.length() != t.length()) return false;
        std::unordered_map<char, int> f, ss;

        for (const auto& ch : s) {
            ++f[ch];
        }

        for (const auto& ch : t) {
            ++ss[ch];
        }

        for (const auto& [ch, x] : f) {
            if (x != ss[ch]) {
                return false;
            }
        }

        return true;
    }
};