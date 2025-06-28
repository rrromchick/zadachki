#include <vector>

class Solution {
public:
    void rotate(std::vector<std::vector<int>>& matrix) {
        int n = matrix.size();
        int i = 0, j = n - 1;

        while (i < j) {
            std::swap(matrix[i++], matrix[j--]);
        }

        for (int i = 0; i < n; ++i) {
            int row = i;
            int col = i;
            while (row < n && col < n) {
                std::swap(matrix[i][col++], matrix[row++][i]);
            }
        }
    }
};