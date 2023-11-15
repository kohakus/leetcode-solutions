// C++ solution.

// sliding window + hash method.
// memorize the last position of the character.
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        std::unordered_map<char, int> pos_map;
        int start_pos = 0;
        int longest_len = 0;
        for (int i = 0; i < s.size(); i++) {
            auto exists_pos = pos_map.find(s[i]);
            if (exists_pos != pos_map.end() && exists_pos->second >= start_pos) {
                start_pos = exists_pos->second + 1;
            }
            pos_map[s[i]] = i;
            longest_len = std::max(longest_len, i-start_pos+1);
        }
        return longest_len;
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