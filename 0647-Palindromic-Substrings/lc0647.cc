// C++ solution.

// Bruteforce. Time: O(N^2)
class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int ans = 0;
        for (int i = 0; i < 2*n-1; i++) {
            int leftp = i / 2;
            int rightp = leftp + (i & 1);
            while (leftp >= 0 && rightp <= n && s[leftp] == s[rightp]) {
                ans++;
                leftp--;
                rightp++;
            }
        }
        return ans;
    }
};