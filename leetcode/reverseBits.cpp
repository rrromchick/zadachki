#include <stdint.h>
#include <vector>
#include <algorithm>

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        std::vector<int> bits(32, 0);
        for (int i = 0; i < bits.size(); ++i) {
            if ((n & (1 << i)) == 0) continue;
            bits[i] = 1;
        }
        std::reverse(bits.begin(), bits.end());
        uint32_t res = 0;
        for (int i = 0; i < bits.size(); ++i) {
            if (bits[i]) res += (1 << i);
        }
        return res;
    }
};