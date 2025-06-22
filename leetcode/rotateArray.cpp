#include <vector>

class Solution {
public:
    void rotate(std::vector<int>& nums, int k) {
        int n = (int)nums.size();
        k = k % n;
        std::vector<int> rotated(n);

        for (int i = 0; i < n; ++i) {
            rotated[(i + k) % n] = nums[i];
        }

        for (int i = 0; i < n; ++i) {
            nums[i] = rotated[i];
        }
    }
};