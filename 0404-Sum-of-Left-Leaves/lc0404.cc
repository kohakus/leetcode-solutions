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
    inline bool isLeaf(TreeNode* node) {
        if (!node) { return false; }
        if (node->left == nullptr && node->right == nullptr) {
            return true;
        }
        return false;
    }

    int sumOfLeftLeaves(TreeNode* root) {
        if (!root) { return 0; }
        if (isLeaf(root->left)) {
            return root->left->val + sumOfLeftLeaves(root->right);
        }
        return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
    }
};