#include <vector>

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        int n = (int)prices.size();
        int ans = 0;
        int cur = -1;

        for (int i = 0; i < n; ++i) {
            if (cur == -1) cur = prices[i];
            if (i && prices[i] >= prices[i-1]) continue;
            else if (i) {
                ans += prices[i-1] - cur;
                cur = prices[i];
            }
        }
        ans += prices[n-1] - cur;

        return ans;
    }
};