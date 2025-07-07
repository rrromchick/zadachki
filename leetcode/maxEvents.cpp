#include <vector>
#include <queue>
#include <algorithm>

class Solution {
public:
    int maxEvents(std::vector<std::vector<int>>& events) {
        std::sort(events.begin(), events.end());

        std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;

        int day = 0, index = 0, n = events.size(), result = 0;

        while (!minHeap.empty() || index < n) {
            if (minHeap.empty()) {
                day = events[index][0];
            }
            while (index < n && events[index][0] <= day) {
                minHeap.push(events[index][1]);
                ++index;
            }
            minHeap.pop();
            ++result;
            ++day;

            while (!minHeap.empty() && minHeap.top() < day) {
                minHeap.pop();
            }
        }
        return result;
    }
};