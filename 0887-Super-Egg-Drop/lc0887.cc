// C++ solution.

// DP with binary search method.
// Time complexity: O(KNlogN), Space complexity: O(KN).
// State f(i, j): the needed minimum number of moves if i eggs are given, considering j floors.
// every test, the eggs can be broken or intact.
// f(K, N) = min_{1 \leqslant x \leqslant N} max(f(K-1, x-1), f(K, N-x));
// use binary search to speed up, O(KN^2) -> O(KNlogN).
class Solution {
public:
    int superEggDrop(int K, int N) {
        vector<vector<int>> dp(K+1, vector<int>(N+1, 0));
        return binary(K, N, dp);
    }

    int binary(int i, int j, vector<vector<int>>& dp) {
        if (i == 1 || j <= 1) { return j; }
        if (dp[i][j] > 0) { return dp[i][j]; }

        int left = 1;
        int right = j;
        int min_move = j;
        while (left < right) {
            int mid = left + (right - left) / 2;
            int broken = binary(i-1, mid-1, dp);
            int intact = binary(i, j-mid, dp);
            min_move = std::min(min_move, 1 + std::max(broken, intact));
            if (broken == intact) {
                break;
            } else if (broken < intact) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        dp[i][j] = min_move;
        return min_move;
    }
};