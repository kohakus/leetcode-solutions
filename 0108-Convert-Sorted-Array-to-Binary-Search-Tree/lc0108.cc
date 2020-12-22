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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helper(nums, 0, nums.size());
    }

    TreeNode* helper(vector<int>& nums, int lpos, int rpos) {
        if (lpos == rpos) { return nullptr; }
        int root_pos = (rpos + lpos) >> 1;
        TreeNode* root = new TreeNode(nums[root_pos]);
        root->left = helper(nums, lpos, root_pos);
        root->right = helper(nums, root_pos+1, rpos);
        return root;
    }
};