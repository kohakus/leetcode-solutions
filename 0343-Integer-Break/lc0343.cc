// C++ solution.

// Math.
// If an optimal product contains a factor f >= 4, then you can replace it with factors 2 and f-2 without losing optimality,
// because 2*(f-2) = 2f-4 >= f.
// So you never need a factor greater than or equal to 4.
// The final method is to use 3 as much as possible, but never use 1.
class Solution {
public:
    int integerBreak(int n) {
        if (n == 2) { return 1; }
        if (n == 3) { return 2; }
        int max_prod = 1;
        while (n - 3 > 1) {
            max_prod *= 3;
            n -= 3;
        }
        return max_prod*n;
    }
};

// DP.
// State f[i]: the result of subproblem of integer i.
// f[i] = max_{j \in [1, i/2]} max(j, f[j]) * max(i-j, f[i-j]).
class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n+1, 0);
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j <= i/2; j++) {
                dp[i] = std::max(dp[i], std::max(j, dp[j]) * std::max(i-j, dp[i-j]));
            }
        }
        return dp[n];
    }
};