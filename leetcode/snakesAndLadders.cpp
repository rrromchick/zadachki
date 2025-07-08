#include <vector>
#include <queue>
#include <algorithm>
#include <numeric>

class Solution {
public:
    int snakesAndLadders(std::vector<std::vector<int>>& board) {
        int n = board.size(), lbl = 1;
        std::vector<std::pair<int, int>> cells(n*n+1);
        std::vector<int> columns(n);
        std::iota(columns.begin(), columns.end(), 0);
        for (int row = n - 1; row >= 0; --row) {
            for (int column : columns) {
                cells[lbl++] = {row, column};
            }
            std::reverse(columns.begin(), columns.end());
        }
        std::vector<int> dist(n*n+1, -1);
        dist[1] = 0;
        std::queue<int> q;
        q.push(1);
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            for (int next = cur + 1; next <= std::min(cur + 6, n*n); ++next) {
                auto [row, column] = cells[next];
                int destination = board[row][column] != -1 ? board[row][column] : next;
                if (dist[destination] == -1) {
                    dist[destination] = dist[cur] + 1;
                    q.push(destination);
                }
            }
        }

        return dist[n*n];
    }
};