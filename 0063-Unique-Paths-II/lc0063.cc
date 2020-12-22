// C++ solution.

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid.empty()) { return 0; }
        int m = obstacleGrid.size();
        int n = obstacleGrid.front().size();

        // 1-d dp array is enough
        vector<int> dp(n, 0);
        dp[0] = 1;
        for (int i = 0; i < m; i++) {
            dp[0] &= (1 - obstacleGrid[i][0]);
            for (int j = 1; j < n; j++) {
                dp[j] = obstacleGrid[i][j] == 1 ? 0 : (dp[j-1] + dp[j]);
            }
        }
        return dp[n-1];
    }
};