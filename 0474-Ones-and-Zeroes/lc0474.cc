// C++ solution.

// simple DP (knapsack).
// Time complexity: O(lmn), Space complexity: O(lmn).
// State f[i][j][k]: the maximum number of strings we can get from the first i argument strs using limited j number of '0's and k number of '1's.
// f[i][j][k] = max(f[i-1][j][k], f[i-1][j-num_zeros(strs[i-1])][k-num_ones(strs[i-1])] + 1);
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        using vec1d = std::vector<int>;
        using vec2d = std::vector<vec1d>;
        using vec3d = std::vector<vec2d>;

        int l = strs.size();
        vec3d dp(l+1, vec2d(m+1, vec1d(n+1, 0)));
        for (int i = 1; i <= l; i++) {
            const std::string& str = strs[i-1];
            int num_zeros = std::count(str.begin(), str.end(), '0');
            int num_ones = str.size() - num_zeros;
            for (int j = 0; j <= m; j++) {
                for (int k = 0; k <= n; k++) {
                    if (j >= num_zeros && k >= num_ones) {
                        dp[i][j][k] = std::max(dp[i-1][j][k], 1 + dp[i-1][j-num_zeros][k-num_ones]);
                    } else {
                        dp[i][j][k] = dp[i-1][j][k];
                    }
                }
            }
        }
        return dp[l][m][n];
    }
};

// Time complexity: O(lmn), Space complexity: O(mn).
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        for (const std::string& str : strs) {
            int num_zeros = std::count(str.begin(), str.end(), '0');
            int num_ones = str.size() - num_zeros;
            for (int j = m; j >= num_zeros; j--) {
                for (int k = n; k >= num_ones; k--) {
                    dp[j][k] = std::max(dp[j][k], 1 + dp[j-num_zeros][k-num_ones]);
                }
            }
        }
        return dp[m][n];
    }
};