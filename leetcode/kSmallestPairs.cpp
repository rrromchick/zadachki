#include <vector>
#include <queue>

class Solution {
public:
    std::vector<std::vector<int>> kSmallestPairs(std::vector<int>& nums1, std::vector<int>& nums2, int k) {
        std::vector<std::vector<int>> resV;
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;

        for (int x : nums1) {
            pq.push({x + nums2[0], 0});
        }

        while (k-- && !pq.empty()) {
            int sum = pq.top().first;
            int pos = pq.top().second;

            resV.push_back({sum - nums2[pos], nums2[pos]});
            pq.pop();

            if (pos + 1 < nums2.size()) {
                pq.push(std::make_pair(sum - nums2[pos] + nums2[pos + 1], pos + 1));
            }
        }

        return resV;
    }
};