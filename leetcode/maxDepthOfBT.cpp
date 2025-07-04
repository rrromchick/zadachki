/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include <queue>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        std::queue<std::pair<TreeNode*, int>> pq;
        pq.push(std::make_pair(root, 1));

        int ans = 0;
        while (!pq.empty()) {
            auto p = pq.front();
            pq.pop();
            ans = std::max(ans, p.second);

            if (p.first->left) pq.push(std::make_pair(p.first->left, p.second + 1));
            if (p.first->right) pq.push(std::make_pair(p.first->right, p.second + 1));
        }

        return ans;
    }
};