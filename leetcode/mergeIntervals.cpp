#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> merge(std::vector<std::vector<int>>& intervals) {
        std::sort(intervals.begin(), intervals.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
            return a[0] < b[0];
        });

        std::vector<std::vector<int>> merged;
        std::vector<int> prev = intervals[0];

        for (int i = 1; i < intervals.size(); ++i) {
            std::vector<int> interval = intervals[i];
            if (interval[0] <= prev[1]) {
                prev[1] = std::max(prev[1], interval[1]);
            } else {
                merged.push_back(prev);
                prev = interval;
            }
        }

        merged.push_back(prev);
        return merged;
    }
};