// C++ solution.

// sliding window.
class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> logger(128, 0);
        for (char c : t) {
            logger[c]++;
        }

        int left = 0;
        int right = 0;
        int cnt = t.size();
        int min_len = s.size() + 1;
        int begin = 0;
        while (right < s.size()) {
            if (logger[s[right]] > 0) {
                cnt--;
            }
            logger[s[right]]--;
            right++;

            while (!cnt) {
                if (right - left < min_len) {
                    min_len = right - left;
                    begin = left;
                }
                logger[s[left]]++;
                if (logger[s[left]] > 0) {
                    cnt++;
                }
                left++;
            }
        }
        return min_len == s.size() + 1 ? "" : s.substr(begin, min_len);
    }
};