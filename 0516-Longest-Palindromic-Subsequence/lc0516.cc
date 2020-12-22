// C++ solution.

// classical range DP.
// Time complexity: O(N^2), Space complexity: O(N^2)
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = n-1; i >= 0; i--) {
            dp[i][i] = 1;
            for (int j = i+1; j < n; j++) {
                if (s[i] == s[j]) {
                    dp[i][j] = dp[i+1][j-1] + 2;
                } else {
                    dp[i][j] = std::max(dp[i][j-1], dp[i+1][j]);
                }
            }
        }
        return dp[0][n-1];
    }
};


// Time complexity: O(N^2), Space complexity: O(N)
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<int> dp(n, 1);
        for (int i = n-1; i >= 0; i--) {
            int prev = 0;
            for (int j = i+1; j < n; j++) {
                int tmp = dp[j];
                if (s[i] == s[j]) {
                    dp[j] = prev + 2;
                } else {
                    dp[j] = std::max(dp[j-1], dp[j]);
                }
                prev = tmp;
            }
        }
        return dp.back();
    }
};