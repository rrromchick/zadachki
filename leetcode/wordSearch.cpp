#include <vector>
#include <string>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#define piii std::pair<std::pair<int, int>, int>

class Solution {
public:
    bool exist(std::vector<std::vector<char>>& board, std::string word) {
        int rows = board.size();
        int cols = board[0].size();
        std::unordered_set<std::string> visited;

        auto dfs = [&](int r, int c, int k, auto& dfs) -> bool {
            if (k == word.length()) {
                return true;
            }

            if (r < 0 || r >= rows || c < 0 || c >= cols || visited.count(std::to_string(r) + "," + std::to_string(c)) || board[r][c] != word[k])
            {
                return false;
            }

            visited.insert(std::to_string(r) + "," + std::to_string(c));
            bool res = dfs(r + 1, c, k + 1, dfs) || dfs(r - 1, c, k + 1, dfs) || dfs(r, c + 1, k + 1, dfs) || dfs(r, c - 1, k + 1, dfs);
            visited.erase(std::to_string(r) + "," + std::to_string(c));
            return res;
        };

        std::unordered_map<char, int> count;
        for (char c : word) {
            ++count[c];
        }

        if (count[word[0]] > count[word.back()]) {
            std::reverse(word.begin(), word.end());
        }

        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (dfs(r, c, 0, dfs)) {
                    return true;
                }
            }
        }

        return false;
    }
};