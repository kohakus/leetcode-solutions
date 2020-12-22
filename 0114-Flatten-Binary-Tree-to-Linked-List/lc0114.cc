// C++ solution.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode* prev = nullptr;
        helper(root, prev);
    }
private:
    void helper(TreeNode* root, TreeNode* &prev) {
        if (root != nullptr) {
            helper(root->right, prev);
            helper(root->left, prev);
            root->right = prev;
            root->left = nullptr;
            prev = root;
        }
    }
};