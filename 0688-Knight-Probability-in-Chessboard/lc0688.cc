// C++ solution.

// DP.
// dp[t][i][j]: start at (i,j), after t rounds, the number of walk that the knight remains on the board.
// dp[t][i][j] = \sum_{di,dj}dp[t-1][i+di][j+dj], if (i+di,j+dj) on the board.
// note that the number of walk may overflow uint64_t, it is better to calculate probability at each steps.
class Solution {
public:
    double knightProbability(int level, int rounds, int row, int column) {
        std::vector<std::vector<double>> dp(level, std::vector<double>(level, 1.0));
        std::vector<std::vector<double>> dp_backup(dp);

        for (int t = 1; t <= rounds; t++) {
            dp.swap(dp_backup);
            for (int i = 0; i < level; i++) {
                for (int j = 0; j < level; j++) {
                    dp[i][j] = 0.0;
                    for (int k = 0; k < 8; k++) {
                        int to_i = i + di[k];
                        int to_j = j + dj[k];
                        if (to_i >= 0 && to_i < level && to_j >= 0 && to_j < level) {
                            dp[i][j] += dp_backup[to_i][to_j] / 8.0;
                        }
                    }
                }
            }
        }
        return dp[row][column];
    }
private:
    const int di[8] = {-2, -2, 2, 2, -1, -1, 1, 1};
    const int dj[8] = {-1, 1, -1, 1, -2, 2, -2, 2};
};