#include <vector>
#include <string>

class Solution {
public:
    std::string convert(std::string s, int numRows) {
        if (numRows == 1 || numRows >= s.length()) {
            return s;
        }

        int idx = 0, d = 1;
        std::vector<std::vector<char>> rows(numRows);

        for (char c : s) {
            rows[idx].push_back(c);
            if (idx == 0) {
                d = 1;
            } else if (idx == numRows - 1) {
                d = -1;
            }
            idx += d;
        }

        std::string result;
        for (const auto& row : rows) {
            for (char c : row) {
                result += c;
            }
        }

        return result;
    }
};