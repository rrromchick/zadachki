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
    TreeNode* buildTree(std::vector<int>& inorder, std::vector<int>& postorder) {
        int n = inorder.size();

        int inStart = 0, inEnd = n-1;
        int postStart = 0, postEnd = n-1;

        return build(inorder, postorder, inStart, inEnd, postStart, postEnd);
    }
private:
    TreeNode* build(std::vector<int>& inorder, std::vector<int>& postorder, int inStart, int inEnd, int postStart, int postEnd) 
    {
        if (inStart > inEnd) return nullptr;

        TreeNode* root = new TreeNode(postorder[postEnd]);

        int i = inStart;
        for (; i <= inEnd; ++i) {
            if (inorder[i] == postorder[postEnd]) {
                break;
            }
        }

        int leftSize = i - inStart;
        int rightSize = inEnd - i;

        root->left = build(inorder, postorder, inStart, i-1, postStart, postStart + leftSize - 1);
        root->right = build(inorder, postorder, i+1, inEnd, postEnd - rightSize, postEnd - 1);

        return root;
    }
};