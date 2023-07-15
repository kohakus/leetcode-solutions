// C++ solution.


// Knapsack problem.
// define P: positive subset
// define N: negative subset
// sum(P) - sum(N) == target
// => sum(P) - sum(N) + sum(P) + sum(N) == target + sum(P) + sum(N)
// => sum(P) == \frac{target + sum(nums)}{2}
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int numsum = accumulate(nums.begin(), nums.end(), 0);
        if (target+numsum < 0 || ((target+numsum) & 1)) {
            return 0;
        }

        // subset sum (0/1 Knapsack)
        int s = (numsum + target) >> 1;
        vector<int> dp(s+1, 0);
        dp[0] = 1;
        for (int num : nums) {
            for (int i = s; i >= num; i--) {
                dp[i] += dp[i-num];
            }
        }
        return dp[s];
    }
};