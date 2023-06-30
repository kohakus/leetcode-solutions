// C++ solution.

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> res;
        vector<vector<int>> ans;
        sort(candidates.begin(), candidates.end());
        backtrack(0, target, candidates, res, ans);
        return ans;
    }

    void backtrack(int cur, int target, vector<int>& candidates, vector<int>& res, vector<vector<int>>& ans) {
        if (!target) {
            ans.push_back(res);
            return;
        }

        for (int i = cur; i < candidates.size(); i++) {
            if (target >= candidates[i]) {
                res.push_back(candidates[i]);
                backtrack(i, target-candidates[i], candidates, res, ans);
                res.pop_back();
            }
        }
    }
};
