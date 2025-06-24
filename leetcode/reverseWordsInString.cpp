#include <string>
#include <vector>

class Solution {
public:
    std::string reverseWords(std::string s) {
        int n = (int)s.length();
        std::string cur;
        std::vector<std::string> v;

        for (int i = 0; i < n; ++i) {
            if (s[i] == ' ') {
                if (cur != "") v.push_back(cur);
                cur = "";
                continue;
            }
            cur += s[i];
        }

        if (cur != "") v.push_back(cur);

        std::string ans;
        for (int i = (int)v.size() - 1; i >= 0; --i) {
            ans += v[i];
            if (i != 0) ans += " ";
        }

        return ans;
    }
};