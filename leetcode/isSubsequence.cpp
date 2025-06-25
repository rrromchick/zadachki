#include <vector>
#include <string>

class Solution {
public:
    bool isSubsequence(std::string s, std::string t) {
        if (s == "") return true;
        
        int n = t.length();
        int m = s.length();

        std::vector<int> a(n, -1);

        for (int i = 0; i < n; ++i) {
            if (i > 0) {
                a[i] = a[i-1];
            }
            int nxt = (a[i] < 0 ? 0 : std::min(m - 1, a[i] + 1));
            if (t[i] == s[nxt]) {
                a[i] = nxt;
                if (nxt == m - 1) {
                    return true;
                }
                continue;
            }
        }

        return false;
    }
};