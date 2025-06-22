#include <vector>

class Solution {
public:
    int candy(std::vector<int>& ratings) {
        int n = (int)ratings.size();
        std::vector<int> a(n, 1);

        for (int i = 1; i < n; ++i) {
            if (ratings[i] > ratings[i-1]) {
                a[i] = a[i-1] + 1;
            }
        }

        int ans = 0;
        for (int i = n - 1; i > 0; --i) {
            if (ratings[i-1] > ratings[i]) {
                a[i-1] = std::max(a[i] + 1, a[i-1]);
            }
            ans += a[i-1];
        }   

        return ans + a[n-1];
    }
};