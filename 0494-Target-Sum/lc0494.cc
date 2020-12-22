// C++ solution.


// 2 * sum(P) == target + sum(nums)
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int numsum = accumulate(nums.begin(), nums.end(), 0);
        if (numsum < S || (S+numsum) & 1) { return 0; }

        // subset sum (0/1 Knapsack)
        int s = (numsum + S) >> 1;
        vector<int> dp(s+1, 0);
        dp[0] = 1;
        for (int n : nums) {
            for (int i = s; i >= n; i--) {
                dp[i] += dp[i-n];
            }
        }
        return dp[s];
    }
};