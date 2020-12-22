// C++ solution.

// DP.
// f[i]: the number of arithmetic slices ending with A[i].
// if A[i-2], A[i-1], A[i] are arithmetic, f[i] = f[i-1] + 1.
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int len = A.size();
        if (len < 3) { return 0; }
        vector<int> dp(len, 0);
        int ans = 0;
        for (int i = 2; i < len; i++) {
            if (A[i]-A[i-1] == A[i-1]-A[i-2]) {
                dp[i] = dp[i-1] + 1;
            }
            ans += dp[i];
        }
        return ans;
    }
};