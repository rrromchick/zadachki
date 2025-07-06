#include <vector>
#include <cstring>

class Solution {
public:
    int numIslands(std::vector<std::vector<char>>& grid) {
        std::memset(vis, false, sizeof(vis));
        int ans = 0;
        int n = grid.size();
        int m = grid[0].size();

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == '1' && !vis[i][j]) {
                    dfs(grid, i, j);
                    ++ans;
                }
            }
        }

        return ans;
    }
private:
    void dfs(std::vector<std::vector<char>>& grid, int i, int j) {
        vis[i][j] = true;
        for (int ii = 0; ii < 4; ++ii) {
            int newx = i + dx[ii];
            int newy = j + dy[ii];
            if (newx < 0 || newy < 0 || newx >= grid.size() || newy >= grid[0].size() || 
                vis[newx][newy] || grid[newx][newy] == '0') 
            { continue; }
            dfs(grid, newx, newy);
        }
    }
    bool vis[301][301];
    int dx[4]{0, 0, -1, 1};
    int dy[4]{-1, 1, 0, 0};
};