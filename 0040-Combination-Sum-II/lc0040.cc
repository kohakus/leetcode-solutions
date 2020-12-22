// C++ solution.

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        if (nums.empty()) { return {}; }
        sort(nums.begin(), nums.end());
        vector<int> res;
        vector<vector<int>> ans;
        helper(nums, target, 0, res, ans);
        return ans;
    }

    void helper(vector<int>& nums, int target, int cur, vector<int>& res, vector<vector<int>>& ans) {
        if (!target) {
            ans.push_back(res);
            return;
        }
        for (int i = cur; i < nums.size(); i++) {
            if (nums[i] > target) {
                return;
            }
            // avoid duplication
            if (i > 0 && nums[i] == nums[i-1] && i > cur) {
                continue;
            }
            res.push_back(nums[i]);
            helper(nums, target-nums[i], i+1, res, ans);
            res.pop_back();
        }
    }
};