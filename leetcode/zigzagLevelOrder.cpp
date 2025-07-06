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
#include <algorithm>

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
    std::vector<std::vector<int>> zigzagLevelOrder(TreeNode* root) {
        std::vector<std::vector<int>> res;
        std::queue<TreeNode*> pq;
        if (root) pq.push(root);

        while (!pq.empty()) {
            std::vector<int> v;
            int size = pq.size();

            for (int i = 0; i < size; ++i) {
                TreeNode* node = pq.front();
                pq.pop();
                v.push_back(node->val);
                if (node->left) pq.push(node->left);
                if (node->right) pq.push(node->right);
            }

            if (res.size() & 1) std::reverse(v.begin(), v.end());
            res.push_back(v);
        }

        return res;
    }
};