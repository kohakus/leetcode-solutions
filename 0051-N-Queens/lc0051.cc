// C++ solution.

class Solution {
public:
  vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> ans;
    vector<int> res(n, -1);
    vector<vector<bool>> states(3, vector<bool>(2*n, false));
    solve(0, states, res, ans);
    return ans;
  }

  void solve(int cur, vector<vector<bool>>& states, vector<int>& res, vector<vector<string>>& ans) {
    const int n = res.size();
    if (cur == n) {
      vector<string> checkerboard(n, string(n, '.'));
      for (int i = 0; i < n; i++){
        checkerboard[i][res[i]] = 'Q';
      }
      ans.push_back(checkerboard);
    }
    for (int i = 0; i < n; i++) {
      if (!states[0][i] && !states[1][cur+i] && !states[2][cur-i+n]) {
        res[cur] = i;
        states[0][i] = states[1][cur+i] = states[2][cur-i+n] = true;
        solve(cur+1, states, res, ans);
        states[0][i] = states[1][cur+i] = states[2][cur-i+n] = false;
      }
    }
  }
};
