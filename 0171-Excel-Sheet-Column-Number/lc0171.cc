// C++ solution.

class Solution {
public:
    int titleToNumber(string s) {
        int ans = 0;
        int num = s.size();
        int coeff = 1;
        for (int i = num-1; i >= 0; i--) {
            if (i < num-1) { coeff *= 26; }
            ans += (s[i]-'A'+1) * coeff;
        }
        return ans;
    }
};