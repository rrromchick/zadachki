#include <vector>

class Solution {
public:
    int maxArea(std::vector<int>& height) {
        int n = (int)height.size();
        int l = 0, r = n - 1;
        int ans = 0;

        while (l < r) {
            int h = std::min(height[l], height[r]);
            int w = r - l;
            ans = std::max(ans, w*h);

            if (height[l] < height[r]) {
                ++l;
            } else {
                --r;
            }
        }

        return ans;
    }
};