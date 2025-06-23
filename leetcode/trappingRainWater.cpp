#include <vector>
#include <algorithm>

class Solution {
public:
    int trap(std::vector<int>& height) {
        int n = (int)height.size();
        int ans = 0;
        int l = 0, r = n - 1;
        int lmax = 0, rmax = 0;

        while (l < r) {
            lmax = std::max(lmax, height[l]);
            rmax = std::max(rmax, height[r]);

            if (lmax < rmax) {
                ans += lmax - height[l];
                ++l;
            } else {
                ans += rmax - height[r];
                --r;
            }
        }

        return ans;
    }
};