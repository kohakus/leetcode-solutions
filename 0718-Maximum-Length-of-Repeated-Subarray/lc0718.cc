// C++ solution.

// DP.
// The problem is related to subarray, so we can try to consider of prefix.
// State f[i][j]: the length of longest common prefix for A[i:] and B[j:].
// f[i][j] = (f[i+1][j+1] + 1) if A[i] == B[j] else 0.
class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int a_len = A.size();
        int b_len = B.size();
        vector<vector<int>> dp(a_len+1, vector<int>(b_len+1, 0));
        int ans = 0;
        for (int i = a_len-1; i >= 0; i--) {
            for (int j = b_len-1; j >= 0; j--) {
                if (A[i] == B[j]) {
                    dp[i][j] = dp[i+1][j+1] + 1;
                    ans = max(ans, dp[i][j]);
                } else {
                    dp[i][j] = 0;
                }
            }
        }
        return ans;
    }
};

// DP with space optimization.
class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int a_len = A.size();
        int b_len = B.size();
        if (!a_len || !b_len) { return 0; }
        vector<int> dp(b_len+1, 0);
        int ans = 0;
        for (int i = a_len-1; i >= 0; i--) {
            for (int j = 0; j < b_len; j++) {
                if (A[i] == B[j]) {
                    dp[j] = 1 + dp[j+1];
                    ans = max(ans, dp[j]);
                } else {
                    dp[j] = 0;
                }
            }
        }
        return ans;
    }
};