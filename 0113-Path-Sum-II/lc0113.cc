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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> ans;
        vector<int> res;
        helper(root, sum, res, ans);
        return ans;
    }
private:
    void helper(TreeNode* root, int sum, vector<int>& res, vector<vector<int>>& ans) {
        if (root == nullptr) { return; }

        // path log
        res.push_back(root->val);

        // leaf node
        if (root->left == nullptr && root->right == nullptr) {
            if (sum == root->val) {
                ans.push_back(res);
            }
        }

        helper(root->left, sum - root->val, res, ans);
        helper(root->right, sum - root->val, res, ans);
        res.pop_back();
    }
};