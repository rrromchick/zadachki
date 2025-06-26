#include <vector>
#include <unordered_map>

class Solution {
public:
    bool isValidSudoku(std::vector<std::vector<char>>& board) {
        for (int i = 0; i < board.size(); ++i) {
            std::unordered_map<int, int> mp;
            for (int j = 0; j < board[i].size(); ++j) {
                if (board[i][j] != '.') ++mp[board[i][j]];
                if (mp[board[i][j]] > 1) {
                    return false;
                }
            }
        }

        for (int j = 0; j < board[0].size(); ++j) {
            std::unordered_map<int, int> mp;
            for (int i = 0; i < board.size(); ++i) {
                if (board[i][j] != '.') ++mp[board[i][j]];
                if (mp[board[i][j]] > 1) {
                    return false;
                }
            }
        }

        std::vector<std::pair<int, int>> startPos = {
            {0,0},{0,3},{0,6},{3,0},{3,3},{3,6},{6,0},{6,3},{6,6}};

        for (const auto& [x, y] : startPos) {
            std::unordered_map<int, int> mp;
            for (int i = 0; i < 3; ++i) {
                for (int j = 0; j < 3; ++j) {
                    int newx = x + i;
                    int newy = y + j;
                    if (board[newx][newy] != '.') ++mp[board[newx][newy]];
                    if (mp[board[newx][newy]] > 1) {
                        return false;
                    }
                }
            }
        }

        return true;
    }
};