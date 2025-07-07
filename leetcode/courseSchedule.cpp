#include <vector>
#include <queue>

class Solution {
public:
    bool canFinish(int numCourses, std::vector<std::vector<int>>& prerequisites) {
        std::vector<int> adj[numCourses];
        std::vector<int> indegree(numCourses, 0);
        std::vector<int> ans;

        for (auto x : prerequisites) {
            adj[x[0]].push_back(x[1]);
            ++indegree[x[1]];
        }

        std::queue<int> pq;
        for (int i = 0; i < numCourses; ++i) {
            if (indegree[i] == 0) {
                pq.push(i);
            }
        }

        while (!pq.empty()) {
            auto t = pq.front();
            ans.push_back(t);
            pq.pop();

            for (auto x : adj[t]) {
                --indegree[x];
                if (indegree[x] == 0) {
                    pq.push(x);
                }
            }
        }
        return ans.size() == numCourses;
    }
};