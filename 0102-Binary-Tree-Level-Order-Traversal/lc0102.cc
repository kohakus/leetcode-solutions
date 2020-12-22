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

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> que;
        if (root != nullptr) {
            que.push(root);
            while (!que.empty()) {
                ans.push_back({});
                int levelcnt = que.size();
                while (levelcnt--) {
                    TreeNode* cur = que.front();
                    que.pop();
                    ans.back().push_back(cur->val);
                    if (cur->left != nullptr) { que.push(cur->left); }
                    if (cur->right != nullptr) { que.push(cur->right); }
                }
            }
        }
        return ans;
    }
};