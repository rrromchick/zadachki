/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
#include <unordered_map>
#include <vector>

class Node {
public:
    int val;
    std::vector<Node*> neighbors;
    Node() { 
        val = 0;
        neighbors = std::vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = std::vector<Node*>();
    }
    Node(int _val, std::vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    Node* cloneGraph(Node* node) {
        std::unordered_map<Node*, Node*> mp;
        if (node == nullptr) {
            return nullptr;
        }
        if (node->neighbors.size() == 0) {
            Node* clone = new Node(node->val);
            return clone;
        }
        return dfs(node,mp);
    }
private:
    Node* dfs(Node* cur, std::unordered_map<Node*, Node*>& mp) {
        std::vector<Node*> neighbor;
        Node* clone = new Node(cur->val);
        mp[cur] = clone;
        for (auto itr : cur->neighbors) {
            if (mp.find(itr) != mp.end()) {
                neighbor.push_back(mp[itr]);
            } else {
                neighbor.push_back(dfs(itr, mp));
            }
        }
        clone->neighbors = neighbor;
        return clone;
    }
};