#include <string>

class Solution {
public:
    std::string makeFancyString(std::string s) {
        std::string ans;
        for (int i = 0; i < s.length(); ++i) {
            int x = 1;
            while (i < s.length() - 1 && s[i] == s[i+1]) {
                ++x;
                ++i;
            }
            if (x == 1) ans += s[i];
            else if (x >= 2) {
                ans += s[i];
                ans += s[i];
            }
        }
        return ans;
    }
};