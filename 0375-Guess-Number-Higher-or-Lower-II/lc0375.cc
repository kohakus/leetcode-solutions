// C++ solution.

// minmax + DP.
// The best strategy to play the game is to minimize the maximum loss you could possibly face.
// state f[i][j]: the money you need to have to guarantee the possible guess process for subproblem on range [i, j].
// So f[1][n] is our target.
// corner case: f[i][i] = 0; f[i][i+1] = i;
// state transition: f[i][j] = min_{k \in [i, j]} k + max(f[i][k-1], f[k+1][j]).

class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n+2, vector<int>(n+2, 0));
        for (int i = n; i >= 1; i--) {
            for (int j = i+1; j <= n; j++) {
                int global_min = std::numeric_limits<int>::max();
                for (int k = i; k <= j; k++) {
                    int local_max = k + std::max(dp[i][k-1], dp[k+1][j]);
                    global_min = std::min(global_min, local_max);
                }
                dp[i][j] = global_min;
            }
        }
        return dp[1][n];
    }
};