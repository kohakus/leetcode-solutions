// C++ solution.

// DP.
// state f[i][j]: the result of subproblem: consider the prefix ending at index i, one can change up to j values from 0 to 1.
// if A[i] == 1: f[i][j] = f[i-1][j] + 1 (no need to change 0s)
// if A[i] == 0: f[i][j] = f[i-1][j-1] + 1 (change A[i] from 0 to 1)
// Time complexity: O(N*K).
class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        if (A.empty()) { return 0; }
        vector<int> dp(K+1, 0);
        int ans = 0;
        for (int i = 0; i < A.size(); i++) {
            for (int j = K; j >= 0; j--) {
                if (!j) {
                    dp[0] = A[i] == 1 ? dp[0]+1 : 0;
                } else {
                    dp[j] = A[i] == 1 ? dp[j]+1 : dp[j-1]+1;
                }
            }
            ans = max(ans, dp[K]);
        }
        return ans;
    }
};

// Sliding window.
// Actually, the problem is to find the maximum length of subArray with atmost K 0s.
// If A[i] ~ A[j] has zeros <= K, we continue to increment j.
// If A[i] ~ A[j] has zeros > K, we increment i (as well as j).
// Time complexity: O(N).
class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int i = 0;
        int j = 0;
        for (; j < A.size(); j++) {
            if (!A[j]) { K--; }
            if (K < 0) {
                if (!A[i++]) {
                    K++;
                }
            }
        }
        return j - i;
    }
};