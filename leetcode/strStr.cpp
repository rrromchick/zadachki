#include <string>

class Solution {
public:
    int strStr(std::string haystack, std::string needle) {
        int n = (int)haystack.length();
        int m = (int)needle.length();

        for (int i = 0; i < n - m + 1; ++i) {
            if (haystack.substr(i, m) == needle) {
                return i;
            }
        }

        return -1;
    }
};