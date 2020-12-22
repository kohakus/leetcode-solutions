// C++ solution.

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    int num = board[i][j] - '0';
                    _hori[i][num-1] = true;
                    _vert[j][num-1] = true;
                    _block[i/3][j/3][num-1] = true;
                }
            }
        }
        backtrack(0, 0, board);
    }

    bool backtrack(const int i, const int j, vector<vector<char>>& board) {
        if (i == 9) { return true; }
        if (j == 9) { return backtrack(i+1, 0, board); }
        if (board[i][j] != '.') {
            return backtrack(i, j+1, board);
        }

        for (int num = 1; num <= 9; num++) {
            if (_hori[i][num-1]) { continue; }
            if (_vert[j][num-1]) { continue; }
            if (_block[i/3][j/3][num-1]) { continue; }

            board[i][j] = static_cast<char>(num+'0');
            _hori[i][num-1] = true;
            _vert[j][num-1] = true;
            _block[i/3][j/3][num-1] = true;

            if (backtrack(i, j+1, board)) {
                return true;
            }

            _block[i/3][j/3][num-1] = false;
            _vert[j][num-1] = false;
            _hori[i][num-1] = false;
            board[i][j] = '.';
        }
        return false;
    }

private:
    std::array<std::array<bool, 9>, 9> _hori{};
    std::array<std::array<bool, 9>, 9> _vert{};
    std::array<std::array<std::array<bool, 9>, 3>, 3> _block{};
};