#include <unordered_set>
#include <string>
#include <queue>

class Solution {
public:
    int minMutation(std::string startGene, std::string endGene, std::vector<std::string>& bank) {
        std::unordered_set<std::string> st(bank.begin(), bank.end());
        std::queue<std::pair<std::string, int>> q;
        std::string genes = "ACGT";
        q.push(std::make_pair(startGene, 0));
        while (!q.empty()) {
            auto [word, level] = q.front();
            q.pop();
            if (word == endGene) {
                return level;
            }
            for (int i = 0; i < 8; ++i) {
                char original = word[i];
                for (auto ch : genes) {
                    word[i] = ch;
                    if (st.find(word) != st.end()) {
                        q.push(std::make_pair(word, level + 1));
                        st.erase(word);
                    }
                }
                word[i] = original;
            }
        }

        return -1;
    }
};