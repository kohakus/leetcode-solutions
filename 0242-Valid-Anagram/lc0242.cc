// C++ solution.

class Solution {
public:
    bool isAnagram(string s, string t) {
        array<int, 26> buckets{};
        for (unsigned char c : s) {
            buckets[c-'a']++;
        }
        for (unsigned char c : t) {
            buckets[c-'a']--;
        }
        for (int i = 0; i < 26; i++) {
            if (buckets[i] != 0) {
                return false;
            }
        }
        return true;
    }
};