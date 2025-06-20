#include <vector>
#include <algorithm>

class Solution {
public:
    void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
        for (int i = m; i < m + n; ++i) {
            nums1[i] = nums2[i-m];
        }
        std::sort(nums1.begin(), nums1.end());
    }
};