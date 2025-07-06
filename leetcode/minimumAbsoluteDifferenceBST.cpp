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
#include <climits>

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
    int getMinimumDifference(TreeNode* root) {
        int ans = INT_MAX;
        std::vector<int> v;
        std::queue<TreeNode*> pq;
        if (root) pq.push(root);

        while (!pq.empty()) {
            TreeNode* node = pq.front();
            pq.pop();
            v.push_back(node->val);

            if (node->left) pq.push(node->left);
            if (node->right) pq.push(node->right);
        }
        std::sort(v.begin(), v.end());
        for (int i = 1; i < v.size(); ++i) {
            ans = std::min(ans, v[i] - v[i-1]);
        }

        return ans;
    }
};