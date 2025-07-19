#include <vector>
#include <string>
#include <algorithm>

class Solution {
public:
    std::vector<std::string> removeSubfolders(std::vector<std::string>& folder) {
        std::sort(folder.begin(), folder.end());
        std::vector<std::string> res;
        for (const auto& f : folder) {
            if (res.empty()) {
                res.push_back(f);
            } else {
                const std::string& prev = res.back();
                if (f.find(prev) == 0 && f.size() > prev.size() && f[prev.size()] == '/') {
                    continue;
                } else {
                    res.push_back(f);
                }
            }
        }

        return res;
    }
};