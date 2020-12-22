// C++ solution.

// range DP.
// Time complexity: O(N^3), Space complexity: O(N^2).
// State f[i][j]: the maximum coins we can get for considering interval [i, j].
// f[i][j] = max_{i \leqslant k \leqslant j} f[i][k-1] + f[k+1][j] + nums[i-1] * nums[k] * nums[j+1];
//     where the index k is the last balloon to be burst in the interval [i, j].
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+2, vector<int>(n+2, 0));
        for (int i = n; i >= 1; i--) {
            for (int j = i; j <= n; j++) {
                for (int k = i; k <= j; k++) {
                    int i_idx = i-1;
                    int j_idx = j-1;
                    int k_idx = k-1;

                    int coins1 = (i == 1) ? 1 : nums[i_idx-1];
                    int coins2 = (j == n) ? 1 : nums[j_idx+1];
                    int last_coins = coins1 * nums[k_idx] * coins2;
                    dp[i][j] = std::max(dp[i][j], dp[i][k-1] + dp[k+1][j] + last_coins);
                }
            }
        }
        return dp[1][n];
    }
};