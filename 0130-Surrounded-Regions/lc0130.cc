// C++ solution.

// DFS implementation
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.empty() || board.front().empty()) { return; }
        int h = board.size();
        int w = board.front().size();

        for (int i = 0; i < w; i++) {
            if (board[0][i] == 'O') { dfs(board, i, 0, h, w); }
            if (board[h-1][i] == 'O') { dfs(board, i, h-1, h, w); }
        }

        for (int i = 0; i < h; i++) {
            if (board[i][0] == 'O') { dfs(board, 0, i, h, w); }
            if (board[i][w-1] == 'O') { dfs(board, w-1, i, h, w); }
        }

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (board[i][j] == 'O') { board[i][j] = 'X'; }
                if (board[i][j] == 'B') { board[i][j] = 'O'; }
            }
        }
    }

    void dfs(vector<vector<char>>& board, int x, int y, int h, int w) {
        auto isValid = [=](int xpos, int ypos) {
            if (ypos < 0 || ypos >= h || xpos < 0 || xpos >= w) {
                return false;
            }
            return true;
        };

        board[y][x] = 'B';
        if (isValid(x+1, y) && board[y][x+1] == 'O') {
            dfs(board, x+1, y, h, w);
        }
        if (isValid(x, y+1) && board[y+1][x] == 'O') {
            dfs(board, x, y+1, h, w);
        }
        if (isValid(x-1, y) && board[y][x-1] == 'O') {
            dfs(board, x-1, y, h, w);
        }
        if (isValid(x, y-1) && board[y-1][x] == 'O') {
            dfs(board, x, y-1, h, w);
        }
    }
};