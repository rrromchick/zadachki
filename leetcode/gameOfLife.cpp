#include <vector>

class Solution {
public:
    void gameOfLife(std::vector<std::vector<int>>& board) {
        std::vector<std::vector<int>> live(board.size(), std::vector<int>(board[0].size(),0));
        std::vector<std::vector<int>> dead = live;

        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                for (int dx = -1; dx <= 1; ++dx) {
                    for (int dy = -1; dy <= 1; ++dy) {
                        if (dx == 0 && dy == 0) continue;
                        
                        int newx = i + dx;
                        int newy = j + dy;

                        if (newx < 0 || newy < 0 || newx >= board.size() || newy >= board[0].size()) {
                            continue;
                        }

                        ++(board[newx][newy] == 0 ? dead[i][j] : live[i][j]);
                    }
                }
            }
        }

        std::vector<std::pair<int, int>> repaint;

        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (board[i][j] == 1) {
                    if (live[i][j] < 2 || live[i][j] > 3) {
                        repaint.push_back(std::make_pair(i, j));
                    }
                } else {
                    if (live[i][j] == 3) {
                        repaint.push_back(std::make_pair(i, j));
                    }
                }
            }
        }

        for (const auto& [x, y] : repaint) {
            board[x][y] = !board[x][y];
        }
    }
};