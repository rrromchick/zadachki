#include <vector>
#include <queue>
#include <algorithm>
#include <numeric>
#define pli std::pair<long long, int>

class Solution {
public:
    int mostBooked(int n, std::vector<std::vector<int>>& meetings) {
        std::sort(meetings.begin(), meetings.end());
        std::vector<int> count(n, 0);
        std::vector<int> freeR(n);
        std::iota(freeR.begin(), freeR.end(), 0);
        std::priority_queue<int, std::vector<int>, std::greater<int>> freeRoom(freeR.begin(), freeR.end());
        std::priority_queue<pli, std::vector<pli>, std::greater<pli>> used;

        for (auto& meet : meetings) {
            int room;
            while (!used.empty() && used.top().first <= meet[0]) {
                room = used.top().second;
                freeRoom.push(room);
                used.pop();
            }
            long long start, m_time = meet[1] - meet[0];
            if (freeRoom.empty()) {
                std::tie(start, room) = used.top();
                used.pop();
            } else {
                room = freeRoom.top();
                start = meet[0];
                freeRoom.pop();
            }
            count[room]++;
            used.push({start + m_time, room});
        }
        int idx = std::max_element(count.begin(), count.end()) - count.begin();
        return idx;
    }
};