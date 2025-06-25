#include <vector>
#include <unordered_map>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& numbers, int target) {
        int n = (int)numbers.size();
        std::unordered_map<int, int> cnt;
        std::vector<int> ans;

        for (int i = 0; i < n; ++i) {
            if (cnt.find(target - numbers[i]) != cnt.end()) {
                ans.push_back(cnt[target - numbers[i]] + 1);
                ans.push_back(i + 1);
                return ans;
            }
            cnt[numbers[i]] = i;
        }

        return {};
    }
};