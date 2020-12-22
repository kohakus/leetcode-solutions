// C++ solution.

// Hash.
class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        unordered_set<string> logger(words.begin(), words.end());
        for (string word : words) {
            // drop suffix
            for (int i = 1; i < word.size(); i++) {
                logger.erase(word.substr(i));
            }
        }
        int res = 0;
        for (const string& word : logger) {
            res += word.size() + 1;
        }
        return res;
    }
};

// Trie.
class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        _root.reset(new TrieNode());
        if (words.empty()) { return 0; }
        sort(words.begin(), words.end(), [](const string& s1, const string& s2) { return s1.size() > s2.size(); });
        int ans = 0;
        for (const string& word : words) {
            if (addStr(word)) {
                ans += word.size() + 1;
            }
        }
        return ans;
    }

private:
    struct TrieNode {
        TrieNode()
            : buckets(26),
              word_end(false) {}

        vector<unique_ptr<TrieNode>> buckets;
        bool word_end;
    };

    bool addStr(const string& word) {
        bool new_str = false;
        TrieNode* cur = _root.get();
        for (int i = word.size()-1; i >= 0; i--) {
            int idx = word[i] - 'a';
            if (!cur->buckets[idx]) {
                new_str = true;
                cur->buckets[idx].reset(new TrieNode());
            }
            cur = cur->buckets[idx].get();
        }
        cur->word_end = true;
        return new_str;
    }

    unique_ptr<TrieNode> _root;
};