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

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if (!root) { return true; }
        return treeHeight(root) != -1;
    }

private:
    // -1 means not balanced
    int treeHeight(TreeNode* root) {
        if (!root->left && !root->right) {
            return 0;
        }

        int left_height = -1;
        if (root->left) {
            left_height = treeHeight(root->left);
            if (left_height == -1) {
                return -1;
            }
        }

        int right_height = -1;
        if (root->right) {
            right_height = treeHeight(root->right);
            if (right_height == -1) {
                return -1;
            }
        }

        if (std::abs(left_height - right_height) > 1) { return -1; }
        return std::max(left_height, right_height) + 1;
    }
};