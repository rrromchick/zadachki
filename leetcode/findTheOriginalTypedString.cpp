#include <unordered_map>
#include <string>

class Solution {
public:
    int possibleStringCount(std::string word) {
        long long int ans = 1;

        for (int i = 1; i < word.length(); ++i) {
            if (word[i] == word[i-1]) {
                ++ans;
            }
        }

        return ans;
    }
};