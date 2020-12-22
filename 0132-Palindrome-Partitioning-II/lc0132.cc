// C++ solution.

// DP.
// state f[i]: consider of the suffix substring that start from i-th element,
//             the minimum number of palindrome partition (which is mini-cuts+1).
// f[i] = min_{i <= k <= N, is_palindrome(i, k)} f[k+1] + 1.
// Time complexity: O(N^2).
class Solution {
public:
    int minCut(string s) {
        int len = s.size();

        // Time complexity: O(N^2), for speeding up palindrome checking of ranges.
        vector<vector<bool>> is_palindrome(len+1, vector<bool>(len+1, false));
        for (int i = len; i >= 1; i--) {
            is_palindrome[i][i] = true;
            is_palindrome[i][i-1] = true;
            for (int j = i+1; j <= len; j++) {
                is_palindrome[i][j] = s[i-1] == s[j-1] ? is_palindrome[i+1][j-1] : false;
            }
        }

        vector<int> dp(len+2, numeric_limits<int>::max());
        dp[len+1] = 0;
        for (int i = len; i >= 1; i--) {
            for (int k = i; k <= len; k++) {
                if (is_palindrome[i][k]) {
                    dp[i] = min(dp[i], 1+dp[k+1]);
                }
            }
        }
        // we should return the number of minimum cuts
        return dp[1]-1;
    }
};