// C++ solution.

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid.front().size(); j++) {
                if (grid[i][j] == '1') {
                    ans++;
                    dfs(grid, i, j);
                }
            }
        }
        return ans;
    }

    // note that this dfs proc will change the input grid.
    void dfs(vector<vector<char>>& grid, int i, int j) {
        int n = grid.size();
        int m = grid.front().size();

        grid[i][j] = '*';
        for (int k = 0; k < 4; k++) {
            int newi = i + di[k];
            int newj = j + dj[k];
            // check if the position is valid.
            if (newi < 0 || newi >= n || newj < 0 || newj >= m) { continue; }
            if (grid[newi][newj] == '1') {
                dfs(grid, newi, newj);
            }
        }
    }

private:
    const int di[4] = {1, 0, -1, 0};
    const int dj[4] = {0, 1, 0, -1};
};