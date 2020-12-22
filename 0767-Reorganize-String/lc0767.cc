// C++ solution.

// First store the frequency of every character,
// then sort the characters by frequency.
// The key idea: print the most common letters alternatingly.
class Solution {
public:
    string reorganizeString(string s) {
        vector<int> freq(26, 0);
        for (int i = 0; i < s.size(); i++) {
            freq[s[i] - 'a']++;
        }
        priority_queue<pair<int, char>> heap;
        for (int i = 0; i < 26; i++) {
            if (freq[i] > 0) {
                heap.push(make_pair(freq[i], 'a'+i));
            }
        }

        string ans;
        while (heap.size() > 1) {
            auto top1 = heap.top();
            heap.pop();
            auto top2 = heap.top();
            heap.pop();
            ans.push_back(top1.second);
            ans.push_back(top2.second);
            if (--top1.first > 0) {
                heap.push(std::move(top1));
            }
            if (--top2.first > 0) {
                heap.push(std::move(top2));
            }
        }
        if (heap.size() == 1 && heap.top().first == 1) {
            if (heap.top().second != ans.back()) {
                ans.push_back(heap.top().second);
                heap.pop();
            }
        }
        return heap.empty() ? ans : "";
    }
};