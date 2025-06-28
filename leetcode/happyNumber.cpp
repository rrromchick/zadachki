#include <unordered_map>
#include <vector>

class Solution {
public:
    bool isHappy(int n) {
        if (n == 1 || n == 7) return true;
        std::unordered_map<int, int> sqs;
        for (int i = 0; i < 10; ++i) {
            sqs[i] = i*i;
        }

        int iter = 10000;
        while (n != 1 && iter > 0) {
            std::vector<int> v;
            int x = n;
            while (x / 10) {
                v.push_back(x % 10);
                x /= 10;
            }
            v.push_back(x);

            x = 0;
            for (const auto& xx : v) {
                x += xx*xx;
            }
            n = x;
            if (n == 1) return true;
            --iter;
            if (iter == 0) return false;
        }

        return true;
    }
};