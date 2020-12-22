// C++ solution.

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (board.empty()) { return false; }
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board.front().size(); j++) {
                if (search(i, j, 0, board, word)) {
                    return true;
                }
            }
        }
        return false;
    }
private:
    // backtracing to search a word.
    bool search(int i, int j, int cur, vector<vector<char>>& board, string& word) {
        if (word[cur] != board[i][j]) { return false; }
        if (cur == word.size()-1) { return true; }

        bool found = false;
        char origchar = board[i][j];
        board[i][j] = '*';
        for (int k = 0; k < 4; k++) {
            int next_i = i + di[k];
            int next_j = j + dj[k];
            if (!invalid(next_i, next_j, board.size(), board.front().size())) {
                if (search(next_i, next_j, cur+1, board, word)) {
                    found = true;
                    break;
                }
            }
        }
        board[i][j] = origchar;
        return found;
    }

    inline bool invalid(int i, int j, int rownum, int colnum) {
        return i >= rownum || i < 0 || j >= colnum || j < 0;
    }

    static constexpr array<int, 4> di = {1, -1, 0, 0};
    static constexpr array<int, 4> dj = {0, 0, 1, -1};
};