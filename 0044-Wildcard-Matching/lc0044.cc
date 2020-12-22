// C++ solution.

// DP.
// State f[i][j]: the corresponding sub-problem of the first i chars of s and the first j chars of p.
// f[0][0] = true;
// f[i][0] = false;
// f[0][j] = if p' is "*...*" => true else false;
// f[i][j] = f[i-1][j-1], if s_i == p_j or p_j == '?';
// f[i][j] = f[i][j-1] || f[i-1][j], if p_j == '*';
class Solution {
public:
    bool isMatch(string s, string p) {
        int s_len = s.size();
        int p_len = p.size();
        vector<vector<bool>> dp(s_len+1, vector<bool>(p_len+1, false));
        dp[0][0] = true;
        for (int i = 0; i < p_len; i++) {
            if (p[i] == '*') {
                dp[0][i+1] = true;
            } else {
                break;
            }
        }
        for (int i = 0; i < s_len; i++) {
            for (int j = 0; j < p_len; j++) {
                if (s[i] == p[j] || p[j] == '?') {
                    dp[i+1][j+1] = dp[i][j];
                }
                if (p[j] == '*') {
                    dp[i+1][j+1] = dp[i+1][j] || dp[i][j+1];
                }
            }
        }
        return dp[s_len][p_len];
    }
};

// Greedy matching.
class Solution {
public:
    bool isMatch(string s, string p) {
        int spointer = 0;
        int ppointer = 0;
        int smatch = 0;
        int star_record = -1;

        int s_len = s.size();
        int p_len = p.size();
        while (spointer < s_len) {
            if (ppointer < p_len &&
                    (s[spointer] == p[ppointer] || p[ppointer] == '?')) {
                spointer++;
                ppointer++;
            } else if (ppointer < p_len && p[ppointer] == '*') {
                star_record = ppointer++;
                smatch = spointer;
            } else if (star_record >= 0) {
                ppointer = star_record + 1;
                spointer = ++smatch;
            } else {
                return false;
            }
        }
        while (ppointer < p_len && p[ppointer] == '*') {
            ppointer++;
        }
        return ppointer == p_len;
    }
};