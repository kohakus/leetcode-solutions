// C++ solution.

// DP with hash to accelerate str finding.
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wdict(make_move_iterator(wordDict.begin()),
                                    make_move_iterator(wordDict.end()));
        vector<bool> dp(s.size()+1, false);
        dp[0] = true;
        for (int i = 1; i <= s.size(); i++) {
            for (int j = i-1; j >= 0; j--) {
                if (dp[j] && wdict.find(s.substr(j, i-j)) != wdict.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.size()];
    }
};