#include <unordered_map>
#include <vector>

class Solution {
public:
    int findLucky(std::vector<int>& arr) {
        std::unordered_map<int, int> mp;

        for (const auto& x : arr) {
            ++mp[x];
        }

        int ans = -1;
        for (const auto& [x, cnt] : mp) {
            if (cnt == x) {
                ans = std::max(ans, x);
            }
        }

        return ans;
    }
};