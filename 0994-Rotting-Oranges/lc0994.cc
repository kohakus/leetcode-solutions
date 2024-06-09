// C++ solution.

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        if (grid.empty()) { return -1; }

        int m = grid.size();
        int n = grid.front().size();

        std::queue<std::pair<int, int>> que;
        int cnt = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    que.push({j,i});
                }
                if (grid[i][j] == 1) {
                    cnt++;
                }
            }
        }

        auto isvalid = [m,n](int x, int y) {
            if (x < 0 || x >= n || y < 0 || y >= m) {
                return false;
            }
            return true;
        };

        int ans = 0;
        for (;!que.empty() && cnt > 0;) {
            int roundsz = que.size();
            ans++;
            for (int i = 0; i < roundsz; i++) {
                auto tobad = que.front();
                que.pop();
                for (int j = 0; j < 4; j++) {
                    int nx = tobad.first + dx[j];
                    int ny = tobad.second + dy[j];
                    if (isvalid(nx, ny) && grid[ny][nx] == 1) {
                        grid[ny][nx] = 2;
                        que.push({nx, ny});
                        cnt--;
                    }
                }
            }
        }
        return cnt > 0 ? -1 : ans;
    }

private:
    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,1,0,-1};
};
