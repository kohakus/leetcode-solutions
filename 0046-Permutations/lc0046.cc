// C++ solution.

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> res;
        vector<bool> used(nums.size(), false);
        backtrack(nums, res, used, ans);
        return ans;
    }

    void backtrack(vector<int>& nums, vector<int>& res, vector<bool>& used, vector<vector<int>>& ans) {
        if (res.size() == nums.size()) {
            ans.push_back(res);
        } else {
            for (int i = 0; i < nums.size(); i++) {
                if (!used[i]) {
                    res.push_back(nums[i]);
                    used[i] = true;
                    backtrack(nums, res, used, ans);
                    res.pop_back();
                    used[i] = false;
                }
            }
        }
    }
};
