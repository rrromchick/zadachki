#include <vector>
#include <unordered_map>

class Solution
{
    public:
        std::vector<int> twoSum(std::vector<int> &nums, int target)
        {
            std::unordered_map<int, int> mp;
            int size = nums.size();
            for (int i = 0; i < size; i++)
            {
                int x = target - nums[i];
                if (mp.count(x)) {
                    return {i, mp[x]};
                }
                mp[nums[i]] = i;
            }
            return {};
        }
};