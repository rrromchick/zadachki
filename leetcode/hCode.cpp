#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    int hIndex(std::vector<int>& citations) {
        int n = (int)citations.size();
        std::unordered_map<int, int> cnt;
        std::vector<int> pref(n + 1);

        int mx = 0;
        for (int i = 0; i < (int)citations.size(); ++i) {
            ++cnt[citations[i]];
            mx = std::max(mx, citations[i]);
        }

        for (int i = mx; i >= n; --i) {
            pref[n] += cnt[i];
        }
        for (int i = n - 1; i >= 0; --i) {
            pref[i] = pref[i+1] + cnt[i];
        }

        for (int i = n; i > 0; --i) {
            if (pref[i] >= i) {
                return i;
            }
        }

        return 0;
    }
};