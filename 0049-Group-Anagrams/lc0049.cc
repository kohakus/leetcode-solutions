// C++ solution.

// Hash + Bucket Sort.
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> logger;
        for (const string& str : strs) {
            logger[sortLowercase(str)].push_back(str);
        }
        for (auto& key_val : logger) {
            ans.push_back(move(key_val.second));
        }
        return ans;
    }

    string sortLowercase(const string& str) {
        array<int, 26> buckets;
        buckets.fill(0);
        for (char c : str) {
            buckets[c - 'a']++;
        }
        string ans(str.size(), 'a');
        int pos = 0;
        for (int i = 0; i < 26; i++) {
            while (buckets[i]--) {
                ans[pos++] = i + 'a';
            }
        }
        return ans;
    }
};