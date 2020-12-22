// C++ solution.

// simple 2D DP. Time: O(MN), Space: O(N)
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty()) { return 0; }
        int h = matrix.size(), w = matrix[0].size();
        int ans = 0, memo = 0;
        vector<int> dp(w, 0);
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                int cur = dp[j];
                int val = matrix[i][j] - '0';
                if (!i || !j || !val) {
                    dp[j] = val;
                } else {
                    dp[j] = min(memo, min(dp[j-1], dp[j])) + 1;
                }
                ans = max(ans, dp[j]);
                memo = cur;
            }
        }
        return ans * ans;
    }
};