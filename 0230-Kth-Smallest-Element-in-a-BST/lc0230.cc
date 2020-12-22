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
    int kthSmallest(TreeNode* root, int k) {
        int ans;
        inorder(root, ans, k);
        return ans;
    }
private:
    void inorder(const TreeNode* root, int& ans, int& k) {
        if (root == nullptr) { return; }
        inorder(root->left, ans, k);
        if (!k) { return; }
        ans = root->val;
        inorder(root->right, ans, --k);
    }
};