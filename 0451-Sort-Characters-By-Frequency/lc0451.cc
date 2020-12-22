// C++ solution.

// bucket sort.
class Solution {
public:
    string frequencySort(string s) {
        array<int, 256> freq{};
        int max_freq = 0;
        for (unsigned char c : s) {
            if (++freq[c] > max_freq) {
                max_freq = freq[c];
            }
        }
        vector<vector<char>> bucket(max_freq+1);
        for (int i = 0; i < 256; i++) {
            if (freq[i] > 0) {
                bucket[freq[i]].push_back(static_cast<char>(i));
            }
        }
        string ans;
        for (int i = max_freq; i >= 0; i--) {
            for (char c : bucket[i]) {
                ans.append(i, c);
            }
        }
        return ans;
    }
};