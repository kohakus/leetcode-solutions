// C++ solution.

// DP.
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int column = matrix.front().size();
        vector<int> dp(column, 0);
        copy(matrix.front().begin(), matrix.front().end(), dp.begin());

        int memo = dp[0];
        for (int i = 1; i < row; i++) {
            for (int j = 0; j < column; j++) {
                int cur = dp[j];
                if (j > 0) {
                    cur = min(memo, cur);
                }
                if (j < column-1) {
                    cur = min(cur, dp[j+1]);
                }
                memo = dp[j];
                dp[j] = cur + matrix[i][j];
            }
        }
        return *min_element(dp.begin(), dp.end());
    }
};