#include <string>
#include <algorithm>

class Solution {
public:
    int lengthOfLastWord(std::string s) {
        int n = (int)s.length();
        int ans = 0;
        std::string cur = "";
        std::string prev;

        for (int i = 0; i < n; ++i) {
            if (s[i] == ' ') {
                ans = std::max(ans, (int)cur.length());
                if (cur != "") prev = cur;
                cur = "";
                continue;
            }
            cur += s[i];
        }
        
        if (cur != "" && cur != prev) prev = cur;
        return (int)prev.length();
    }
};