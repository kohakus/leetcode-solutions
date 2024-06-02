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
    void flatten(TreeNode* root) {
        TreeNode* prev = nullptr;
        helper(root, prev);
    }
private:
    void helper(TreeNode* root, TreeNode* &prev) {
        if (root != nullptr) {
            helper(root->right, prev);
            helper(root->left, prev);
            root->right = prev;
            root->left = nullptr;
            prev = root;
        }
    }
};

// another way
class Solution {
public:
    void flatten(TreeNode* root) {
        helper(root);
    }

    TreeNode* helper(TreeNode* root) {
        if (root == nullptr) { return nullptr; }
        if (root->left == nullptr && root->right == nullptr) { return root; }
        TreeNode* ltail = helper(root->left);
        TreeNode* rtail = helper(root->right);
        if (ltail) {
            ltail->right = root->right;
            root->right = root->left;
        }
        root->left = nullptr;
        return rtail == nullptr? ltail : rtail;
    }
};
