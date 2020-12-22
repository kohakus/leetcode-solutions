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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root) { return {}; }
        queue<TreeNode*> que;
        que.push(root);
        bool isltor = true;
        vector<vector<int>> ans;

        while (!que.empty()) {
            int que_size = que.size();
            vector<int> line_vals(que_size);
            for (int i = 0; i < que_size; i++) {
                TreeNode* top = que.front();
                int emplace_pos = isltor ? i : que_size-1 - i;
                line_vals[emplace_pos] = top->val;
                if (top->left)  { que.push(top->left); }
                if (top->right) { que.push(top->right); }
                que.pop();
            }
            ans.push_back(line_vals);
            isltor = !isltor;
        }
        return ans;
    }
};