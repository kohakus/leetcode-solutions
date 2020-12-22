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
    int maxPathSum(TreeNode* root) {
        int ans = numeric_limits<int>::min();
        search(root, ans);
        return ans;
    }
private:
    // check the max sum of the current sub-tree
    // as well as provide chain sum of one side to its parent
    int search(TreeNode* root, int& ans) {
        if (root == nullptr) { return 0; }
        int lsc = search(root->left, ans);
        int rsc = search(root->right, ans);
        int res = root->val;
        res += lsc > 0 ? lsc : 0;
        res += rsc > 0 ? rsc : 0;
        ans = max(ans, res);
        return max(root->val, max(lsc, rsc) + root->val);
    }
};