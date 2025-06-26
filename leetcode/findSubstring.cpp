#include <unordered_map>
#include <vector>
#include <string>

class Solution {
    std::unordered_map<std::string, unsigned int> map;
public:
    std::vector<int> findSubstring(std::string s, std::vector<std::string>& words) {
        std::vector<int> result;

        unsigned int length = words[0].length();

        map.clear();
        for (const std::string& word : words) {
            ++map[word];
        }

        for (unsigned int offset = 0; offset < length; ++offset) {
            unsigned int size = 0;
            std::unordered_map<std::string, unsigned int> seen;

            for (unsigned int i = offset; i + length <= s.size(); i += length) {
                std::string sub = s.substr(i, length);

                auto itr = map.find(sub);
                if (itr == map.end()) {
                    seen.clear();
                    size = 0;
                    continue;
                }

                ++seen[sub];
                ++size;

                while (seen[sub] > itr->second) {
                    std::string first = s.substr(i - (size - 1) * length, length);

                    --seen[first];
                    --size;
                }

                if (size == words.size()) {
                    result.push_back(i - (size - 1) * length);
                }
            }
        }
        return result;
    }
};