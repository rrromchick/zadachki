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
#include <vector>
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
    std::vector<int> rightSideView(TreeNode* root) {
        std::vector<int> res;
        std::queue<TreeNode*> q;
        if (root) q.push(root);

        while (!q.empty()) {
            TreeNode* rightSide = nullptr;
            int size = q.size();

            for (int i = 0; i < size; ++i) {
                TreeNode* node = q.front();
                q.pop();
                if (node) {
                    rightSide = node;
                    if (node->left) q.push(node->left);
                    if (node->right) q.push(node->right);
                }
            }

            if (rightSide) {
                res.push_back(rightSide->val);
            }
        }

        return res;
    }
};