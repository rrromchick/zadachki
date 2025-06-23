#include <string>

class Solution {
public:
    int romanToInt(std::string s) {
        int n = s.length();
        int ans = 0;

        for (int i = 0; i < n; ++i) {
            if (s[i] == 'I') {
                if (i < n - 1 && (s[i+1] == 'X' || s[i+1] == 'V')) {
                    ans += (s[i+1] == 'X' ? 9 : 4);
                    ++i;
                    continue;
                }
                ++ans;
            } else if (s[i] == 'X') {
                if (i < n - 1 && (s[i+1] == 'L' || s[i+1] == 'C')) {
                    ans += (s[i+1] == 'L' ? 40 : 90);
                    ++i;
                    continue;
                }
                ans += 10;
            } else if (s[i] == 'C') {
                if (i < n - 1 && (s[i+1] == 'D' || s[i+1] == 'M')) {
                    ans += (s[i+1] == 'D' ? 400 : 900);
                    ++i;
                    continue;
                }
                ans += 100;
            } else {
                switch (s[i]) {
                    case 'V': ans += 5; break;
                    case 'L': ans += 50; break;
                    case 'D': ans += 500; break;
                    case 'M': ans += 1000; break;
                }
            }
        }

        return ans;
    }
};