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

// Idea
// Very simple question, just add the last value of each level.
// Both BFS or DFS are ok.

// DFS
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        helper(root, ans, 0);
        return ans;
    }

    void helper(TreeNode* root, vector<int>& ans, int level_cnt) {
        if (root == nullptr) { return; }
        if (level_cnt >= ans.size()) {
            ans.push_back(root->val);
        }
        if (root->right) { helper(root->right, ans, level_cnt+1); }
        if (root->left) { helper(root->left, ans, level_cnt+1); }
    }
};

// BFS
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if (root == nullptr) { return ans; }

        queue<TreeNode*> que;
        que.push(root);
        while (!que.empty()) {
            size_t level_cnt = que.size();
            for (size_t i = 0; i < level_cnt; i++) {
                TreeNode* ptop = que.front();
                que.pop();
                if (ptop->left) { que.push(ptop->left); }
                if (ptop->right) { que.push(ptop->right); }
                if (i == level_cnt-1) { ans.push_back(ptop->val); }
            }
        }
        return ans;
    }
};