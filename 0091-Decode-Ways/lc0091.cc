// C++ solution.

// DP.
// State f[i]: the corresponding sub-problem of s[0..i].
// if s[i] == '0' =>
//     1. if s[i-1] == '1' or s[i-1] == '2' => f[i] = f[i-2];
//     2. else => failed.
// else if s[i-1] == '1' => f[i] = f[i-1] + f[i-2];
// else if s[i-1] == '2' and s[i] in ['1'..'6'] => f[i] = f[i-1] + f[i-2];
class Solution {
public:
    int numDecodings(string s) {
        if (s.empty() || s.front() == '0') { return 0; }
        int pre = 1;
        int cur = 1;
        for (int i = 1; i < s.size(); i++) {
            int tmp = cur;
            if (s[i] == '0') {
                if (s[i-1] == '1' || s[i-1] == '2') {
                    cur = pre;
                } else {
                    // failed to decode.
                    return 0;
                }
            } else {
                if (s[i-1] == '1' || (s[i-1] == '2' && s[i] <= '6')) {
                    // new current dp value.
                    cur += pre;
                }
            }
            pre = tmp;
        }
        return cur;
    }
};