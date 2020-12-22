// C++ solution.

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> res;
        vector<bool> used(nums.size(), false);
        sort(nums.begin(), nums.end());
        helper(nums, ans, res, used);
        return ans;
    }

    void helper(vector<int>& nums, vector<vector<int>>& ans, vector<int>& res, vector<bool>& used) {
        if (res.size() == nums.size()) {
            ans.push_back(res);
            return;
        }

        int last_pos = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (!used[i]) {
                if (last_pos == -1 || nums[last_pos] != nums[i]) {
                    res.push_back(nums[i]);
                    used[i] = true;
                    last_pos = i;
                    helper(nums, ans, res, used);
                    res.pop_back();
                    used[i] = false;
                }
            }
        }
    }
};