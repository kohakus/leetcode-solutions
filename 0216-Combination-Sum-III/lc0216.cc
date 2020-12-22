// C++ solution.

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> res;
        helper(ans, res, 1, 0, k, n);
        return ans;
    }

private:
    void helper(vector<vector<int>>& ans, vector<int>& res, const int cur, const int sum, const int k, const int n) {
        if (!k) {
            if (sum == n) {
                ans.push_back(res);
            }
            return;
        }
        for (int i = cur; i <= 9; i++) {
            if (sum + i > n) { return; }
            res.push_back(i);
            helper(ans, res, i+1, sum+i, k-1, n);
            res.pop_back();
        }
    }
};