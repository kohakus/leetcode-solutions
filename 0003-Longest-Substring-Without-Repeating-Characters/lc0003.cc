// C++ solution.

// sliding window + hash method.
// memorize the last position of the character.
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        std::unordered_map<char, int> poslog;
        int start = 0;
        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            if (poslog.find(s[i]) != poslog.end()) {
                start = std::max(start, poslog[s[i]] + 1);
            }
            poslog[s[i]] = i;
            ans = std::max(ans, i-start+1);
        }
        return ans;
    }
};

// the same idea, but without unordered_map.
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> poslog(256, -1);
        int start = 0;
        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            if (poslog[s[i]] >= start) {
                start = poslog[s[i]] + 1;
            }
            poslog[s[i]] = i;
            ans = std::max(ans, i-start+1);
        }
        return ans;
    }
};