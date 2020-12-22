// C++ solution.

// Simple package problem.
// Note that put coins in outer loop is better.
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, amount+1);
        dp[0] = 0;

        for (int c : coins) {
            for (int am = c; am <= amount; am++) {
                dp[am] = min(dp[am], dp[am-c] + 1);
            }
        }
        return dp.back() > amount ? -1 : dp.back();
    }
};