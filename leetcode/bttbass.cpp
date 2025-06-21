#include <vector>
#include <algorithm>

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        int n = (int)prices.size();
        std::vector<int> suffMax(n);

        for (int i = n - 1; i >= 0; --i) {
            suffMax[i] = std::max((i == n - 1 ? 0 : suffMax[i+1]), prices[i]);
        }        

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans = std::max(ans, suffMax[i] - prices[i]);
        }

        return ans;
    }
};