#include <string>
#include <vector>
#include <algorithm>

class Solution {
public:
    int minDistance(std::string word1, std::string word2) {
        int n = word1.length();
        int m = word2.length();
        std::vector<int> prev(m + 1), cur(m + 1);
        for (int i = 0; i <= m; ++i) { prev[i] = i; }
        for (int i = 1; i <= n; ++i) {
            cur[0] = i;
            for (int j = 1; j <= m; ++j) {
                if (word1[i-1] == word2[j-1]) {
                    cur[j] = prev[j-1];
                } else {
                    cur[j] = 1 + std::min({cur[j-1], prev[j], prev[j-1]});
                }
            }
            prev = cur;
        }
        return prev[m];
    }
};