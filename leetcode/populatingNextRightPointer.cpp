/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/
#include <queue>
#include <unordered_map>

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}

    Node(int _val) : val(_val), left(nullptr), right(nullptr), next(nullptr) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        if (root == nullptr) return root;
        std::queue<std::pair<Node*, int>> pq;
        pq.push(std::make_pair(root, 0));
        std::unordered_map<int, std::vector<Node*>> mp;

        while (!pq.empty()) {
            auto f = pq.front();
            pq.pop();
            
            mp[f.second].push_back(f.first);

            if (f.first->left) pq.push(std::make_pair(f.first->left, f.second + 1));
            if (f.first->right) pq.push(std::make_pair(f.first->right, f.second + 1));
        }

        for (const auto& [x, vec] : mp) {
            for (int i = 0; i < vec.size() - 1; ++i) {
                vec[i]->next = vec[i+1];
            }
        }

        return root;
    }
};