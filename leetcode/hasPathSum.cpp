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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) return false;

        std::queue<std::pair<TreeNode*, int>> pq;
        pq.push(std::make_pair(root, targetSum - root->val));

        while (!pq.empty()) {
            auto f = pq.front();
            pq.pop();

            if (f.second == 0 && !f.first->left && !f.first->right) return true;

            if (f.first->left) pq.push(std::make_pair(f.first->left, f.second - f.first->left->val));
            if (f.first->right) pq.push(std::make_pair(f.first->right, f.second - f.first->right->val));
        }

        return false;
    }
};