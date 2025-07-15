#include <vector>
#include <algorithm>

class Solution {
public:
    bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
        if (matrix.size() == 1) {
            return std::find(matrix[0].begin(), matrix[0].end(), target) != matrix[0].end();
        }
        std::vector<int> v;
        for (int i = 0; i < matrix.size(); ++i) {
            if (matrix[i][0] == target) return true;
            v.push_back(matrix[i][0]);
        }
        auto it = std::lower_bound(v.begin(), v.end(), target);
        int row = it - v.begin() - 1;
        if (row < 0) return false;
        return std::find(matrix[row].begin(), matrix[row].end(), target) != matrix[row].end();
    }
};