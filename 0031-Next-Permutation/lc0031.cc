// C++ solution.

// pandita's algorithm
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // find the corresponding LCA(Lowest Common Ancestor)
        int lca = nums.size() - 2;
        for (; lca >= 0; lca--) {
            if (nums[lca] < nums[lca+1]) {
                break;
            }
        }
        if (lca < 0) {
            reverse(nums.begin(), nums.end());
        } else {
            int bro = nums.size() - 1;
            for (; bro > lca; bro--) {
                if (nums[bro] > nums[lca]) {
                    break;
                }
            }
            // go to the next sub-tree
            swap(nums[lca], nums[bro]);
            // go to the first leaf node, which is the result
            reverse(nums.begin()+lca+1, nums.end());
        }
    }
};