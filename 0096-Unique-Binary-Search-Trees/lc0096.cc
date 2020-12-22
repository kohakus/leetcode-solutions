// C++ solution.

// simple DP
class Solution {
public:
    int numTrees(int n) {
        if (n <= 2) { return n; }
        vector<int> dp(n+1, 0);
        dp[0] = dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                dp[i] += dp[j-1] * dp[i-j];
            }
        }
        return dp[n];
    }
};

// Catalan Number: \frac{1}{n+1}\binom{2n}{n}
class Solution {
public:
    int numTrees(int n) {
        long ans = 1;
        for (int k = 1; k <= n; k++) {
            ans = ans * (2*n - k + 1) / k;
        }
        return ans/(n+1);
    }
};