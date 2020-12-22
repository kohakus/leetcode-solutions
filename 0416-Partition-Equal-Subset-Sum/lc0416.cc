// C++ solution.

// Simple DP (Knapsack). Time: O(NS)
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int numsum = accumulate(nums.begin(), nums.end(), 0);
        if (numsum & 1) { return false; }

        int s = numsum >> 1;
        vector<bool> dp(s+1, false);
        dp[0] = true;
        for (int n : nums) {
            for (int i = s; i >= n; i--) {
                dp[i] = dp[i] || dp[i-n];
            }
            if (dp[s]) { return true; }
        }
        return false;
    }
};

// Optimization: using bitset. Time: O(N)
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        const int MAX_NUM = 100;
        const int MAX_SIZE = 200;
        const int MAX_SUM = (MAX_NUM * MAX_SIZE) >> 1;
        bitset<MAX_SUM+1> dp(1);

        int sum = 0;
        for (int n : nums) {
            sum += n;
            dp |= dp << n;
        }

        return !(sum & 1) && dp[sum >> 1];
    }
};