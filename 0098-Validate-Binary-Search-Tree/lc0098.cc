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

// simple recursive version, can also try morris traversal
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        TreeNode* pre = nullptr;
        return inorderCheck(root, pre);
    }

    bool inorderCheck(TreeNode* root, TreeNode* &pre) {
        if (root == nullptr) { return true; }
        if (!inorderCheck(root->left, pre)) { return false; }
        if (pre != nullptr && pre->val >= root->val) { return false; }
        pre = root;
        return inorderCheck(root->right, pre);
    }
};