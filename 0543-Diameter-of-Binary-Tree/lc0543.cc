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
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        // calculate the diameter while finding the height of a Tree
        height(root, diameter);
        return diameter;
    }
private:
    int height(TreeNode* root, int& diameter) {
        // the height of a leaf node is zero
        if (root == nullptr) { return -1; }
        if (root->left == nullptr && root->right == nullptr) { return 0; }

        int hl = height(root->left, diameter);
        int hr = height(root->right, diameter);
        diameter = max(diameter, hl+hr+2);
        return 1 + max(hl, hr);
    }
};