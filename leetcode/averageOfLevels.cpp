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
    std::vector<double> averageOfLevels(TreeNode* root) {
        std::vector<double> res;
        std::queue<TreeNode*> pq;
        if (root) pq.push(root);

        while (!pq.empty()) {
            double sum = 0, cnt = 0;
            int size = pq.size();

            for (int i = 0; i < size; ++i) {
                TreeNode* node = pq.front();
                pq.pop();
                sum += node->val;
                ++cnt;
                if (node->left) pq.push(node->left);
                if (node->right) pq.push(node->right);
            }

            res.push_back(sum / cnt);
        }

        return res;
    }
};