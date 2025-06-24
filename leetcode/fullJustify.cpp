#include <vector>
#include <string>

class Solution {
public:
    std::vector<std::string> fullJustify(std::vector<std::string>& words, int maxWidth) {
        int n = (int)words.size();
        std::vector<std::pair<int, std::vector<std::string>>> ans;
        int idx = 0;
        ans.push_back(std::make_pair(words[0].length(), std::vector<std::string>{words[0]}));

        for (int i = 1; i < n; ++i) {
            if (ans[idx].first + words[i].length() + ans[idx].second.size() <= maxWidth) {
                ans[idx].second.push_back(words[i]);
                ans[idx].first += words[i].length();
                continue;
            }
            
            ans.push_back(std::make_pair(words[i].length(), std::vector<std::string>{words[i]}));
            ++idx;
        } 

        std::vector<std::string> res;

        for (int i = 0; i < ans.size(); ++i) {
            if (i != ans.size() - 1) {
                std::string s;
                int spaces = maxWidth - ans[i].first;
                int r = spaces % (std::max(1, (int)ans[i].second.size() - 1));
                int w = spaces / (std::max(1, (int)ans[i].second.size() - 1));

                for (int j = 0; j < ans[i].second.size() - 1; ++j) {
                    s += ans[i].second[j];
                    for (int k = 0; k < w + (j < r ? 1 : 0); ++k) {
                        s += " ";
                        --spaces;
                    }
                }

                s += ans[i].second[ans[i].second.size() - 1];
                if (ans[i].second.size() == 1) {
                    for (int k = 0; k < spaces; ++k) {
                        s += " ";
                    }
                }
                res.push_back(s);
            } else {
                std::string s;
                int spaces = maxWidth - ans[i].first;
                for (int j = 0; j < ans[i].second.size() - 1; ++j) {
                    s += ans[i].second[j] + " ";
                    --spaces;
                }

                s += ans[i].second[ans[i].second.size() - 1];
                for (int k = 0; k < spaces; ++k) {
                    s += " ";
                }
                res.push_back(s);
            }
        }

        return res;
    }
};