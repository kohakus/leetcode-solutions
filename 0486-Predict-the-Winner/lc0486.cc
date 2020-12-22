// C++ solution.

// Game, Minimax.
// the DP method.
// state f[i][j]: the maximum score player-1 can get when considering range [i, j].
// each player want to win the game, so player-2 don't want to let player-1 win.
// each player plays to maximize his score, player-2 will make a decision that let the player-1 get lower score.
// if player-1 select the left hand value, the maximum score he will get in this case: min(dp[i+2][j], dp[i+1][j-1]) + nums[i].
// if player-1 select the right hand value, the maximum score he will get in this case: min(dp[i+1][j-1], dp[i][j-2]) + nums[j].
// the player-1 want to get more score, so dp[i][j] = max(left_selection, right_selection).
class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        if (nums.empty()) { return true; }
        vector<vector<int>> dp(nums.size(), vector<int>(nums.size(), 0));

        // length of range == 1
        for (int i = 0; i < nums.size(); i++) {
            dp[i][i] = nums[i];
        }

        // length of range == 2
        for (int i = 0; i < nums.size()-1; i++) {
            dp[i][i+1] = max(nums[i], nums[i+1]);
        }

        for (int len = 3; len <= nums.size(); len++) {
            for (int i = 0; i + len - 1 < nums.size(); i++) {
                int j = i + len - 1;
                int left_selection = min(dp[i+2][j], dp[i+1][j-1]) + nums[i];
                int right_selection = min(dp[i+1][j-1], dp[i][j-2]) + nums[j];
                dp[i][j] = max(left_selection, right_selection);
            }
        }

        return 2*dp[0][nums.size()-1] >= accumulate(nums.begin(), nums.end(), 0) ? true : false;
    }
};