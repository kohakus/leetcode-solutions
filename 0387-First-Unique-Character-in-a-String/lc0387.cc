// C++ solution.

// Hash table, Time complexity O(N), Space complexity O(1).
class Solution {
public:
    int firstUniqChar(string s) {
        std::array<int, 26> buckets{};
        for (char c : s) {
            buckets[c-'a']++;
        }
        for (int i = 0; i < s.size(); i++) {
            if (buckets[s[i]-'a'] == 1) {
                return i;
            }
        }
        return -1;
    }
};