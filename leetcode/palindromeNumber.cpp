#include <string>
#include <algorithm>

class Solution {
public:
    bool isPalindrome(int x) {
        std::string str = std::to_string(x);
        std::string rev = str;
        std::reverse(rev.begin(), rev.end());
        return str == rev;
    }
};