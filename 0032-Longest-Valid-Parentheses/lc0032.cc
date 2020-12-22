// C++ solution.

// using stack.
// Time complexity: O(N)
class Solution {
public:
    int longestValidParentheses(string s) {
        // the stack stk stores the index of parentheses
        stack<int> stk;
        stk.push(-1);
        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                stk.push(i);
            } else {
                stk.pop();
                if (stk.empty()) {
                    stk.push(i);
                } else {
                    ans = std::max(ans, i-stk.top());
                }
            }
        }
        return ans;
    }
};

// DP method, counting left parentheses.
// Time complexity: O(N)
// State f[i]: the longest length of valid parentheses which is end at i;
// 1. We count all the '(';
// 2. If we find a ')' and '(' counter is not 0, we have at least a valid result size of 2;
// 3. Check the the one before (i - 1). If f[i-1] is not 0, we have something like "(())";
// 4. We might have something before "(())". Take "()(())" as example;
class Solution {
public:
    int longestValidParentheses(string s) {
        int len = s.size();
        vector<int> dp(len, 0);
        int cnt = 0;
        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                cnt++;
                continue;
            }
            if (cnt > 0) {
                dp[i] = 2 + dp[i-1];
                if (i-dp[i] > 0) {
                    dp[i] += dp[i-dp[i]];
                }
                ans = std::max(ans, dp[i]);
                cnt--;
            }
        }
        return ans;
    }
};