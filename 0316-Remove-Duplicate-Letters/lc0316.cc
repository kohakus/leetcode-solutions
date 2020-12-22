// C++ solution.

// Greedy.
// Idea: every time check whether it is possible to use duplicate letters to make a smaller string.
class Solution {
public:
    string removeDuplicateLetters(string s) {
        // we need to know whether a letter has duplicates, as well as the number of that.
        array<int, 26> freq;
        array<bool, 26> used;
        freq.fill(0);
        used.fill(false);
        for (unsigned char c : s) {
            freq[c-'a']++;
        }
        string ans;
        for (unsigned char c : s) {
            int idx = c - 'a';
            freq[idx]--;
            if (used[idx]) { continue; }
            // delete the characters if we can use duplicates to make a smaller string.
            while (!ans.empty() && ans.back() > c && freq[ans.back()-'a'] > 0) {
                used[ans.back()-'a'] = false;
                ans.pop_back();
            }
            ans.push_back(c);
            used[idx] = true;
        }
        return ans;
    }
};