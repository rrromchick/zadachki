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
#include <algorithm>
#include <string>

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
    int sumNumbers(TreeNode* root) {
        if (!root) return 0;
        int ans = 0;

        std::queue<std::pair<TreeNode*, int>> pq;
        pq.push(std::make_pair(root, root->val));

        while (!pq.empty()) {
            auto f = pq.front();
            pq.pop();

            if (!f.first->left && !f.first->right) {
                ans += f.second;
                continue;
            }

            if (f.first->left) {
                pq.push(std::make_pair(
                    f.first->left, atoi((std::to_string(f.second)+
                    std::to_string(f.first->left->val)).c_str())));
            }
            if (f.first->right) {
                pq.push(std::make_pair(
                    f.first->right, atoi((std::to_string(f.second)+
                    std::to_string(f.first->right->val)).c_str())));
            }
        }

        return ans;
    }
};