// C++ solution.

struct TrieNode {
    TrieNode()
        : buckets(26),
          word_end(false) {}

    std::vector<std::unique_ptr<TrieNode>> buckets;
    bool word_end;
};

class Trie {
public:
    /** Initialize your data structure here. */
    Trie() : _root(new TrieNode()) {}

    /** Inserts a word into the trie. */
    void insert(const std::string& word) {
        TrieNode* cur = _root.get();
        for (const char c : word) {
            int idx = c - 'a';
            if (!cur->buckets[idx]) {
                cur->buckets[idx].reset(new TrieNode());
            }
            cur = cur->buckets[idx].get();
        }
        cur->word_end = true;
    }

    /** Returns if the word is in the trie. */
    bool search(const std::string& word) {
        TrieNode* node = find(word);
        if (node && node->word_end) {
            return true;
        }
        return false;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(const std::string& prefix) {
        return find(prefix) != nullptr;
    }

private:
    TrieNode* find(const std::string& str) {
        TrieNode* cur = _root.get();
        for (const char c : str) {
            int idx = c - 'a';
            if (!cur->buckets[idx]) {
                return nullptr;
            }
            cur = cur->buckets[idx].get();
        }
        return cur;
    }

    std::unique_ptr<TrieNode> _root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */