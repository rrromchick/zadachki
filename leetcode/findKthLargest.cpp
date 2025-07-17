#include <vector>
#include <queue>

class Solution {
public:
    int findKthLargest(std::vector<int>& nums, int k) {
        std::priority_queue<int> pq;
        for (const auto& x : nums) {
            pq.push(x);
        }

        int x = 1;
        while (!pq.empty()) {
            auto f = pq.top();
            pq.pop();
            if (x == k) {
                return f;
            }
            ++x;
        }
        return 0;
    }
};