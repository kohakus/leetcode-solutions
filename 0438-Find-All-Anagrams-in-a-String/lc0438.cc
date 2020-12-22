// C++ solution.

// sliding window method.
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if (s.size() < p.size()) { return {}; }
        vector<int> pbucket(26, 0);
        vector<int> sbucket(26, 0);
        for (int i = 0; i < p.size(); i++) {
            pbucket[p[i]-'a']++;
            sbucket[s[i]-'a']++;
        }

        vector<int> ans;
        if (pbucket == sbucket) { ans.push_back(0); }
        for (int i = p.size(); i < s.size(); i++) {
            sbucket[s[i]-'a']++;
            sbucket[s[i-p.size()]-'a']--;
            if (pbucket == sbucket) {
                ans.push_back(i-p.size()+1);
            }
        }
        return ans;
    }
};