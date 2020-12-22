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

// Naive DFS
class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        if (root == nullptr) { return 0; }
        return rootPathSum(root, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
    }

    int rootPathSum(TreeNode* root, int sum) {
        if (root == nullptr) { return 0; }
        int checkRoot = root->val == sum ? 1 : 0;
        return checkRoot + rootPathSum(root->left, sum - root->val) + rootPathSum(root->right, sum - root->val);
    }
};