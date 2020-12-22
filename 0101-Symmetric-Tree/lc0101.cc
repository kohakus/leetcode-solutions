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
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) { return true; }
        return flipEqual(root->left, root->right);
    }

    bool flipEqual(TreeNode* root1, TreeNode* root2) {
        if (root1 == nullptr && root2 == nullptr) {
            return true;
        } else if (root1 == nullptr || root2 == nullptr) {
            return false;
        } else if (root1->val != root2->val) {
            return false;
        } else {
            return flipEqual(root1->left, root2->right) && flipEqual(root1->right, root2->left);
        }
    }
};