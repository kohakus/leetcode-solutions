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
    int distributeCoins(TreeNode* root) {
        int ans = 0;
        moveCount(root, ans);
        return ans;
    }

    int moveCount(const TreeNode* root, int& total_cnt) {
        if (root == nullptr) {
            return 0;
        }
        int cntl = 0;
        int cntr = 0;
        if (root->left) {
            cntl = moveCount(root->left, total_cnt);
        }
        if (root->right) {
            cntr = moveCount(root->right, total_cnt);
        }
        total_cnt += std::abs(cntl) + std::abs(cntr);
        return cntl + cntr + root->val - 1;
    }
};