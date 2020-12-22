// C++ solution.

class Solution {
public:
  vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> ans;
    vector<int> res(k, 0);
    dfs(ans, res, 1, n, k);
    return ans;
  }

  void dfs(vector<vector<int>>& ans, vector<int>& res, int start, const int n, const int k) {
    if (k == 0) {
      ans.push_back(res);
    } else {
      for (int i = start; i <= (n-k+1); i++) {
        res[res.size()-k] = i;
        dfs(ans, res, i+1, n, k-1);
      }
    }
  }
};
