#include <vector>
#include <string>

class Solution {
public:     
    int total = 0;
    
    bool isSafe(std::vector<std::string> &board, int row, int col, int n) {
        for (int i = 0; i < row; ++i) {
            if (board[i][col] == 'Q') return false;
        }

        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j) {
            if (board[i][j] == 'Q') return false;
        }

        for (int i = row - 1, j = col + 1; i >= 0 && j < n; --i, ++j) {
            if (board[i][j] == 'Q') return false;
        }

        return true;
    }

    void nQueen(std::vector<std::string> &board, int row, int n, std::vector<std::vector<std::string>> &ans) {
        if (row == n) {
            ans.push_back(board);
            ++total;
            return;
        }

        for (int j = 0; j < n; ++j) {
            if (isSafe(board, row, j, n)) {
                board[row][j] = 'Q';
                nQueen(board, row + 1, n, ans);
                board[row][j] = '.';
            }
        }
    }

    std::vector<std::vector<std::string>> solveNQueens(int n) {
        std::vector<std::string> board(n, std::string(n, '.'));
        std::vector<std::vector<std::string>> ans;
        nQueen(board, 0, n, ans);
        return ans;
    }

    int totalNQueens(int n) {
        total = 0;
        std::vector<std::vector<std::string>> dummy;
        std::vector<std::string> board(n, std::string(n, '.'));
        nQueen(board, 0, n, dummy);
        return total;
    }
};