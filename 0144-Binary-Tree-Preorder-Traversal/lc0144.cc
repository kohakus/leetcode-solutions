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

// trivial recursive method
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        dfs(root, ans);
        return ans;
    }

    void dfs(TreeNode* root, vector<int>& ans) {
        if (root == nullptr) { return; }
        ans.push_back(root->val);
        if (root->left) { dfs(root->left, ans); }
        if (root->right) { dfs(root->right, ans); }
    }
};

// Morris traversal
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode* cur = root;
        TreeNode* pre = nullptr;
        while (cur) {
            if (cur->left == nullptr) {
                ans.push_back(cur->val);
                cur = cur->right;
            } else {
                pre = cur->left;
                while (pre->right && pre->right != cur) {
                    pre = pre->right;
                }
                if (pre->right == nullptr) {
                    pre->right = cur;
                    ans.push_back(cur->val);
                    cur = cur->left;
                } else {
                    pre->right = nullptr;
                    cur = cur->right;
                }
            }
        }
        return ans;
    }
};