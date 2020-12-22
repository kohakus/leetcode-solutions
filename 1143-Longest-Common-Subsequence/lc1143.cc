// C++ solution.

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        if (text1.size() < text2.size()) { text1.swap(text2); }
        vector<int> pre_dp(text2.size()+1, 0);
        vector<int> cur_dp(text2.size()+1, 0);

        for (int i = 1; i <= text1.size(); i++) {
            for (int j = 1; j <= text2.size(); j++) {
                if (text1[i-1] == text2[j-1]) {
                    cur_dp[j] = pre_dp[j-1] + 1;
                } else {
                    cur_dp[j] = max(pre_dp[j], cur_dp[j-1]);
                }
            }
            pre_dp.swap(cur_dp);
        }
        return pre_dp[text2.size()];
    }
};