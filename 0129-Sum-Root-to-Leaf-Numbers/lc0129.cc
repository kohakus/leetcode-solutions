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
    int sumNumbers(TreeNode* root) {
        int ans = 0;
        if (root) { helper(root, 0, ans); }
        return ans;
    }

    void helper(TreeNode* root, int acc, int& ans) {
        if (root->left == nullptr && root->right == nullptr) {
            ans += acc + root->val;
            return;
        }
        int cur_acc = 10 * (acc + root->val);
        if (root->left) {
            helper(root->left, cur_acc, ans);
        }
        if (root->right) {
            helper(root->right, cur_acc, ans);
        }
    }
};