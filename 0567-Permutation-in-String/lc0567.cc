// C++ solution.

// sliding window method.
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> hash(26, 0);
        int cnt = s1.size();

        for (char c : s1) {
            hash[c-'a']++;
        }

        int start = 0;
        for (int i = 0; i < s2.size(); i++) {
            if (hash[s2[i]-'a']-- > 0) {
                cnt--;
            }

            while (cnt == 0) {
                if (i-start+1 == s1.size()) { return true; }
                if (++hash[s2[start++]-'a'] > 0) {
                    cnt++;
                }
            }
        }
        return false;
    }
};