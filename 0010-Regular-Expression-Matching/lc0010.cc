// C++ solution.

// DP solution.
// State f[i][j]: represents subproblem result for the first i chars of str(s) and the first j chars of pattern(p).
// (assume the index of array is start from 1 for p[] and s[])
// if p[j] == s[i]: f[i][j] = f[i-1][j-1];
// if p[j] == '.': f[i][j] = f[i-1][j-1];
// if p[j] == '*':
//     1. if p[j-1] != s[i] and p[j-1] != '.': f[i][j] = f[i][j-2]. (c* matches empty)
//     2. if p[j-1] == s[i] or p[j-1] == '.':
//            f[i][j] = f[i-1][j] || f[i][j-1] || f[i][j-2]. (c* matches multiple, single or empty)

class Solution {
public:
    bool isMatch(string s, string p) {
        int slen = s.size();
        int plen = p.size();
        vector<vector<bool>> dp(slen+1, vector<bool>(plen+1, false));

        // deal with boundary: s is empty.
        dp[0][0] = true;
        for (int j = 2; j <= plen; j+=2) {
            if (p[j-1] == '*' && dp[0][j-2]) {
                dp[0][j] = true;
            }
        }

        for (int i = 1; i <= slen; i++) {
            for (int j = 1; j <= plen; j++) {
                if (p[j-1] == '.' || p[j-1] == s[i-1]) {
                    dp[i][j] = dp[i-1][j-1];
                }
                if (p[j-1] == '*') {
                    if (s[i-1] != p[j-2] && p[j-2] != '.') {
                        dp[i][j] = dp[i][j-2];
                    } else {
                        dp[i][j] = dp[i-1][j] || dp[i][j-1] || dp[i][j-2];
                    }
                }
            }
        }
        return dp[slen][plen];
    }
};