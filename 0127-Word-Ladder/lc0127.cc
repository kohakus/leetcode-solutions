// C++ solution.

// Simple BFS, use hashing to speed up searching phase.
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> word_lst(wordList.begin(), wordList.end());
        if (word_lst.find(endWord) == word_lst.end()) {
            return 0;
        }

        queue<string> que;
        que.push(beginWord);
        int word_size = beginWord.size();
        int level_cnt = 0;

        while (!que.empty()) {
            ++level_cnt;
            for (int level_num = que.size(); level_num > 0; level_num--) {
                string cur_s = que.front();
                que.pop();
                for (char& c : cur_s) {
                    char cur_c = c;
                    for (int t = 'a'; t <= 'z'; t++) {
                        c = t;
                        if (cur_s == endWord) { return level_cnt+1; }
                        if (word_lst.find(cur_s) != word_lst.end()) {
                            que.push(cur_s);
                            word_lst.erase(cur_s);
                        }
                    }
                    c = cur_c;
                }
            }
        }
        return 0;
    }
};