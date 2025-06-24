#include <string>
#include <algorithm>

class Solution {
public:
    bool isPalindrome(std::string s) {
        int n = (int)s.length();
        std::string str;
        
        for (int i = 0; i < n; ++i) {
            if (std::isalpha(s[i]) || std::isdigit(s[i])) {
                str += std::tolower(s[i]);
            }
        }

        std::string a = str;
        std::reverse(str.begin(), str.end());

        if (a == str) {
            return true;
        }

        return false;
    }
};