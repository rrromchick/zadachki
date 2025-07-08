#include <unordered_set>
#include <queue>
#include <string>

class Solution {
public:
    int ladderLength(std::string beginWord, std::string endWord, std::vector<std::string>& wordList) {
        std::unordered_set<std::string> wordSet(wordList.begin(), wordList.end());
        if (!wordSet.count(endWord)) return 0;

        std::queue<std::string> q;
        q.push(beginWord);
        int steps = 1;

        while (!q.empty()) {
            int size = q.size();

            for (int i = 0; i < size; ++i) {
                std::string word = q.front();
                q.pop();

                for (int j = 0; j < word.length(); ++j) {
                    char original = word[j];
                    for (char c = 'a'; c <= 'z'; ++c) {
                        if (c == original) continue;

                        word[j] = c;
                        if (word == endWord) return steps + 1;

                        if (wordSet.count(word)) {
                            q.push(word);
                            wordSet.erase(word);
                        }
                    }

                    word[j] = original;
                }
            }

            ++steps;
        }

        return 0;
    }
};