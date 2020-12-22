// C++ solution.

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int> dp(triangle.back());
        for (int nrow = triangle.size()-2; nrow >= 0; nrow--) {
            for (int i = 0; i <= nrow; i++) {
                dp[i] = min(dp[i], dp[i+1]) + triangle[nrow][i];
            }
        }
        return dp[0];
    }
};