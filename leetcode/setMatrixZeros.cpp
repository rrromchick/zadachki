#include <vector>
#include <unordered_map>

class Solution {
public:
    void setZeroes(std::vector<std::vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        std::unordered_map<int, int> rows, cols;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (matrix[i][j] != 0) continue;
                ++cols[i];
                ++rows[j];
            }
        }

        for (int i = 0; i < n; ++i) {
            if (cols.find(i) != cols.end()) {
                for (int j = 0; j < m; ++j) {
                    matrix[i][j] = 0;
                }
            }
        }

        for (int j = 0; j < m; ++j) {
            if (rows.find(j) != cols.end()) {
                for (int i = 0; i < n; ++i) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};