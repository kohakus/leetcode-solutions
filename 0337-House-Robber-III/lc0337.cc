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

// DP on tree.
class Solution {
public:
    int rob(TreeNode* root) {
        pair<int, int> ans(search(root));
        return pairmax(ans);
    }

    pair<int, int> search(TreeNode* root) {
        if (root == nullptr) { return make_pair(0, 0); }
        pair<int, int> leftRes(search(root->left));
        pair<int, int> rightRes(search(root->right));
        int robmax = leftRes.second + rightRes.second + root->val;
        int unrobmax = pairmax(leftRes) + pairmax(rightRes);
        return make_pair(robmax, unrobmax);
    }

    inline int pairmax(const pair<int, int>& intpair) {
        return intpair.first > intpair.second ? intpair.first : intpair.second;
    }
};