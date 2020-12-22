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

// simple recursive method.
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return helper(inorder, postorder, 0, inorder.size()-1, 0, postorder.size()-1);
    }

private:
    TreeNode* helper(vector<int>& inorder, vector<int>& postorder, int in_l, int in_r, int post_l, int post_r) {
        if (post_l > post_r) { return nullptr; }
        TreeNode* root = new TreeNode(postorder[post_r]);
        int len_l = std::find(inorder.begin()+in_l, inorder.begin()+in_r+1, root->val) - inorder.begin() - in_l;
        root->left = helper(inorder, postorder, in_l, in_l+len_l-1, post_l, post_l+len_l-1);
        root->right = helper(inorder, postorder, in_l+len_l+1, in_r, post_l+len_l, post_r-1);
        return root;
    }
};