// C++ solution.

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if (grid.empty() || grid.front().empty()) { return 0; }
        int ans = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid.front().size(); j++) {
                if (grid[i][j] == 1) {
                    ans = std::max(ans, dfs(grid, i, j));
                }
            }
        }
        return ans;
    }

    int dfs(vector<vector<int>>& grid, int posi, int posj) {
        if (grid[posi][posj] != 1) { return 0; }
        int h = grid.size();
        int w = grid.front().size();
        int area = 1;
        grid[posi][posj] = -1;

        for (int i = 0; i < 4; i++) {
            int next_posi = posi + di[i];
            int next_posj = posj + dj[i];
            if (valid(next_posi, next_posj, h, w)) {
                area += dfs(grid, next_posi, next_posj);
            }
        }
        return area;
    }

    inline bool valid(const int posi, const int posj, const int h, const int w) {
        if (posi < 0 || posi >= h || posj < 0 || posj >= w) {
            return false;
        }
        return true;
    }

private:
    const array<int, 4> di{0, 1, 0, -1};
    const array<int, 4> dj{1, 0, -1, 0};
};