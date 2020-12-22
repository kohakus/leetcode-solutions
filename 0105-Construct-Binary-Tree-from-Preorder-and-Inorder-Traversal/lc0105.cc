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

// simple recursion
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder, inorder, 0, preorder.size()-1, 0, inorder.size()-1);
    }
private:
    TreeNode* build(vector<int>& prearr, vector<int>& inarr, int pre_b, int pre_e, int in_b, int in_e) {
        if (pre_b > pre_e) { return nullptr; }
        TreeNode* root = new TreeNode(prearr[pre_b]);
        int idx = find(inarr.begin(), inarr.end(), root->val) - inarr.begin();
        root->left = build(prearr, inarr, pre_b+1, pre_b+idx-in_b, in_b, idx-1);
        root->right = build(prearr, inarr, pre_b+idx-in_b+1, pre_e, idx+1, in_e);
        return root;
    }
};

// optimization, without root index finding in the inorder array
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int pre_pos = 0, in_pos = 0;
        return build(preorder, inorder, nullptr, pre_pos, in_pos);
    }
private:
    TreeNode* build(vector<int>& prearr, vector<int>& inarr, TreeNode* stop, int& pre_pos, int& in_pos) {
        if (pre_pos >= prearr.size() || in_pos >= inarr.size()) { return nullptr; }
        if (stop == nullptr || inarr[in_pos] != stop->val) {
            TreeNode* root = new TreeNode(prearr[pre_pos++]);
            root->left = build(prearr, inarr, root, pre_pos, in_pos);
            in_pos++;
            root->right = build(prearr, inarr, stop, pre_pos, in_pos);
            return root;
        }
        return nullptr;
    }
};