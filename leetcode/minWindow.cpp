#include <string>
#include <unordered_map>
#include <climits>

class Solution {
    std::unordered_map<char, int> cnt;
public:
    std::string minWindow(std::string s, std::string t) {
        if (s.length() < t.length()) {
            return "";
        }

        int m = (int)s.length();
        int n = (int)t.length();

        for (const char& c : t) {
            ++cnt[c];
        }

        int targetCharsRemaining = t.length();
        int minWindow[2] = {0, INT_MAX};
        int startIndex = 0;

        for (int endIndex = 0; endIndex < s.length(); ++endIndex) {
            char c = s[endIndex];
            if (cnt.find(c) != cnt.end() && cnt[c] > 0) {
                --targetCharsRemaining;
            }
            --cnt[c];

            if (targetCharsRemaining == 0) {
                while (true) {
                    char charAtStart = s[startIndex];
                    if (cnt.find(charAtStart) != cnt.end() && cnt[charAtStart] == 0) {
                        break;
                    }
                    ++cnt[charAtStart];
                    ++startIndex;
                }

                if (endIndex - startIndex < minWindow[1] - minWindow[0]) {
                    minWindow[0] = startIndex;
                    minWindow[1] = endIndex;
                }

                ++cnt[s[startIndex]];
                ++targetCharsRemaining;
                ++startIndex;
            }
        }

        return minWindow[1] >= s.length() ? "" : s.substr(minWindow[0], minWindow[1] - minWindow[0] + 1);
    }
};