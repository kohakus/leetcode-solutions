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

// trivial recursive method.
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        dfs(root, ans);
        return ans;
    }

    void dfs(TreeNode* root, vector<int>& ans) {
        if (root == nullptr) { return; }
        if (root->left) { dfs(root->left, ans); }
        if (root->right) { dfs(root->right, ans); }
        ans.push_back(root->val);
    }
};

// Morris traversal.
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        TreeNode dumb;
        dumb.left = root;

        vector<int> ans;
        TreeNode* cur = &dumb;
        TreeNode* pre = nullptr;
        while (cur) {
            if (cur->left == nullptr) {
                cur = cur->right;
            } else {
                pre = cur->left;
                while (pre->right && pre->right != cur) {
                    pre = pre->right;
                }
                if (pre->right == nullptr) {
                    pre->right = cur;
                    cur = cur->left;
                } else {
                    pre->right = nullptr;
                    reverseShow(cur->left, pre, ans);
                    cur = cur->right;
                }
            }
        }
        return ans;
    }

private:
    void reverseShow(TreeNode* from, TreeNode* to, vector<int>& ans) {
        reverseListNodes(from);
        TreeNode* node = to;
        while (true) {
            ans.push_back(node->val);
            if (node == from) { break; }
            node = node -> right;
        }
        reverseListNodes(to);
    }

    void reverseListNodes(TreeNode* start) {
        TreeNode* x = start;
        TreeNode* y = nullptr;
        TreeNode* z = nullptr;
        while (x) {
            y = x->right;
            x->right = z;
            z = x;
            x = y;
        }
    }
};