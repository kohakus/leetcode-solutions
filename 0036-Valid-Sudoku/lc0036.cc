// C++ solution.

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        std::array<std::array<bool, 9>, 9> hori{};
        std::array<std::array<bool, 9>, 9> vert{};
        std::array<std::array<std::array<bool, 9>, 3>, 3> block{};

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    int num = board[i][j] - '0';
                    if (hori[i][num-1]) { return false; }
                    if (vert[j][num-1]) { return false; }
                    if (block[i/3][j/3][num-1]) { return false; }
                    hori[i][num-1] = true;
                    vert[j][num-1] = true;
                    block[i/3][j/3][num-1] = true;
                }
            }
        }
        return true;
    }
};