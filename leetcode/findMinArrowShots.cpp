#include <vector>
#include <algorithm>

class Solution {
public:
    int findMinArrowShots(std::vector<std::vector<int>>& points) {
        std::sort(points.begin(), points.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
            return a[1] < b[1];
        });

        int arrows = 1, end = points[0][1];
        for (int i = 1, n = points.size(); i < n; ++i) {
            if (points[i][0] > end) {
                end = points[i][1];
                ++arrows;
            }
        }
        return arrows;
    }
};