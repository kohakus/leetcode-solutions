// C++ solution.

// Directly try to expand at each position to check all possible palindromes.
// The possible palindrome pattern can be odd or even.
class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size() < 2) { return s; }
        // to save the start and end index of the current longest palindrome.
        int start = 0;
        int end = 0;
        for (int i = 0; i < s.size(); i++) {
            int len_odd = expand(s, i, i);
            int len_even = expand(s, i, i+1);
            int len = std::max(len_odd, len_even);
            if (len > end-start+1) {
                start = i - (len-1)/2;
                end = i + len/2;
            }
        }
        return s.substr(start, end-start+1);
    }

private:
    int expand(string& s, int left, int right) {
        while (left >= 0 && right < s.size()) {
            if (s[left] == s[right]) {
                left--;
                right++;
            } else {
                break;
            }
        }
        return right - left - 1;
    }
};

// DP.
// state f[i][j]: whether s[i...j] is a parindrome string.
// f[i][i] = true;
// f[i][i+1] = true if s[i] == s[i+1];
// f[i][j] = (s[i] == s[j]) && f[i+1][j-1].
class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.size();
        if (len < 2) { return s; }
        int start = 0;
        int end = 0;
        vector<vector<bool>> dp(len, vector<bool>(len, false));
        for (int i = len-1; i >= 0; i--) {
            for (int j = i; j < len; j++) {
                dp[i][j] = (s[i] == s[j]) && (j - i < 2 || dp[i+1][j-1]);
                if (dp[i][j] && j-i > end-start) {
                    start = i;
                    end = j;
                }
            }
        }
        return s.substr(start, end-start+1);
    }
};