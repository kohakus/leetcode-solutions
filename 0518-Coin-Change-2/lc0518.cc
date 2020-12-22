// C++ solution.

// simple DP (Knapsack).
// Time complexity: O(NM), Space complexity: O(NM).
// State f[i][j]: the number of combinations to make up amount j by using the first i types coins.
// f[i][0] = 1;
// f[i][j] = f[i-1][j] + f[i][j - coins[i]], if j >= coins[i];

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n+1, vector<int>(amount+1, 0));
        dp[0][0] = 1;
        for (int i = 1; i <= n; i++) {
            dp[i][0] = 1;
            for (int j = 1; j <= amount; j++) {
                dp[i][j] = dp[i-1][j];
                if (j >= coins[i-1]) {
                    dp[i][j] += dp[i][j-coins[i-1]];
                }
            }
        }
        return dp[n][amount];
    }
};

// Time complexity: O(NM), Space complexity: O(M).
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount+1, 0);
        dp[0] = 1;
        for (int coin : coins) {
            for (int i = coin; i <= amount; i++) {
                dp[i] += dp[i-coin];
            }
        }
        return dp[amount];
    }
};