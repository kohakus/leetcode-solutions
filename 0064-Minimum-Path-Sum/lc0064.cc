// C++ solution.

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.empty()) { return 0; }
        int m = grid.size();
        int n = grid.front().size();

        // 1-d dp array is enough
        vector<int> dp(n, numeric_limits<int>::max());
        dp[0] = 0;
        for (int i = 0; i < m; i++) {
            dp[0] += grid[i][0];
            for (int j = 1; j < n; j++) {
                dp[j] = min(dp[j], dp[j-1]) + grid[i][j];
            }
        }
        return dp[n-1];
    }
};