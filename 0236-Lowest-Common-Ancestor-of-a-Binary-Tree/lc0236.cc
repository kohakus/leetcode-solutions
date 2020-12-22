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

// Naive DFS
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) { return nullptr; }
        if (p == root || q == root) { return root; }

        TreeNode* searchl = lowestCommonAncestor(root->left, p, q);
        TreeNode* searchr = lowestCommonAncestor(root->right, p, q);

        if (searchl == nullptr) { return searchr; }
        if (searchr == nullptr) { return searchl; }
        return root;
    }
};