#include <vector>
#include <string>
#include <unordered_map>

class Solution {
public:
    bool dfs(std::string src, std::string target, double& num, std::unordered_map<std::string, bool>& visited)  
    {
        visited[src] = 1;
        for (auto nbr : adj[src]) {
            if (nbr.first == target) {
                num = nbr.second;
                return true;
            } else if (!visited[nbr.first]) {
                if (dfs(nbr.first, target, num, visited)) {
                    num *= nbr.second;
                    return true;
                }
            }
        }
        return false;
    }

    std::vector<double> calcEquation(std::vector<std::vector<std::string>>& equations, std::vector<double>& values, std::vector<std::vector<std::string>>& queries) 
    {
        for (int i = 0; i < equations.size(); ++i) {
            std::string u = equations[i][0], v = equations[i][1];
            double w = values[i];
            adj[u][v] = w;
            adj[v][u] = 1.0 / w;
        }    

        std::vector<double> res;
        for (auto &q : queries) {
            std::string src = q[0], dest = q[1];
            if (!adj.count(src) || !adj.count(dest)) {
                res.push_back(-1.0);
            } else if (src == dest) {
                res.push_back(1.0);
            } else {
                std::unordered_map<std::string, bool> visited;
                double result = -1.0;
                dfs(src, dest, result, visited);
                res.push_back(result);
            }
        }
        return res;
    }
private:
    std::unordered_map<std::string, std::unordered_map<std::string, double>> adj;
};