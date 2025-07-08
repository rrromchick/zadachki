#include <vector>
#include <algorithm>

class Solution {
public:
    int maxValue(std::vector<std::vector<int>>& events, int k) {
        std::sort(events.begin(), events.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
            return a[1] < b[1];
        });

        int n = events.size();
        std::vector<std::vector<int>> dp(n + 1, std::vector<int>(k + 1, 0));

        for (int i = 1; i <= n; ++i) {
            int prev = binarySearch(events, events[i-1][0]);

            for (int j = 1; j <= k; ++j) {
                dp[i][j] = std::max(dp[i-1][j], dp[prev+1][j-1] + events[i-1][2]);
            }
        }

        return dp[n][k];
    }
private:
    int binarySearch(std::vector<std::vector<int>>& events, int currentStart) {
        int left = 0, right = events.size() - 1;
        int result = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (events[mid][1] < currentStart) {
                result = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return result;
    }
};