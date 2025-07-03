#include <string>

class Solution {
public:
    char kthCharacter(int k) {
        std::string s = "a";

        while (s.length() <= k) {
            std::string t = s;
            for (int i = 0; i < s.length(); ++i) {
                t[i] = s[i] + 1;
            }
            s += t;
        }

        return s[k-1];
    }
};