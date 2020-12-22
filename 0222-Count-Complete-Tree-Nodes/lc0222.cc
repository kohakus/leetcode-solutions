// C++ solution.

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

// recursive method.
// The subtree of a complete binary tree is also a complete binary tree.
class Solution {
public:
    int countNodes(TreeNode* root) {
        if (!root) { return 0; }
        int lv_l = level(root->left);
        int lv_r = level(root->right);
        if (lv_l == lv_r) {
            return (1 << lv_l) + countNodes(root->right);
        } else {
            return (1 << lv_r) + countNodes(root->left);
        }
    }

private:
    int level(TreeNode* root) {
        if (!root) { return 0; }
        return 1 + level(root->left);
    }
};