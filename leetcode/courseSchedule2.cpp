#include <vector>
#include <queue>
#include <algorithm>

class Solution {
public:
    std::vector<int> findOrder(int numCourses, std::vector<std::vector<int>>& prerequisites) {
        int n = numCourses;
        int size = prerequisites.size();
        std::vector<std::vector<int>> adj(n);
        
        for (int i = 0; i < size; ++i) {
            int nu = prerequisites[i][0];
            int ad = prerequisites[i][1];
            adj[nu].push_back(ad);
        }

        std::queue<int> q;
        std::vector<int> topo;

        std::vector<int> incoming(numCourses, 0);
        for (int i = 0; i < numCourses; ++i) {
            for (auto it : adj[i]) {
                ++incoming[it];
            }
        }

        for (int i = 0; i < numCourses; ++i) {
            if (incoming[i] == 0) q.push(i);
        }

        while (!q.empty()) {
            int number = q.front();
            q.pop();
            topo.push_back(number);
            for (auto it : adj[number]) {
                --incoming[it];
                if (incoming[it] == 0) q.push(it);
            }
        }

        std::reverse(topo.begin(), topo.end());
        std::vector<int> nothing;
        return topo.size() == numCourses ? topo : nothing;
    }
};