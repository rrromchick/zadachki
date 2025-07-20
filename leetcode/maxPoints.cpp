#include <vector>
#include <map>
#include <math.h>

class Solution {
public:
    int maxPoints(std::vector<std::vector<int>>& points) {
        int ans = 1;
        int n = points.size();

        for (int i = 0; i < n - 1; ++i) {
            std::map<double, int> mp;
            for (int j = i + 1; j < n; ++j) {
                double x = (double)(points[j][1] - points[i][1]) / (double)(points[j][0] - points[i][0]);
                if (points[j][1] - points[i][1]  < 0 && (points[j][0] - points[i][0]) == 0) {
                    mp[std::abs(x)]++;
                } else {
                    mp[x]++;
                }
            }

            int temp = 0;
            for (auto it : mp) {
                temp = std::max(temp, it.second + 1);
            }
            ans = std::max(temp, ans);
        }

        return ans;
    }
};