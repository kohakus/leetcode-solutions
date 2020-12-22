// C++ solution.

// The DP structure of this problem is similar to LIS.
// Idea: if a > b > c, a % b = 0, b % c = 0, then a % c = 0.
// So we can sort the input array, and check if a larger one can be added to the current subset.
// state f[i]: the length of the largest divisible subset whose largest number is nums[i].
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        if (!n) { return {}; }

        sort(nums.begin(), nums.end());
        vector<int> dp(n, 1);

        // we need to return a longest divisible subset,
        // use an array to store the path.
        vector<int> prev(n, -1);

        int end_idx = 0;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0 && dp[i] < dp[j]+1) {
                    dp[i] = dp[j] + 1;
                    prev[i] = j;
                }
            }
            if (dp[i] > dp[end_idx]) {
                end_idx = i;
            }
        }

        // use end_idx and prev to get the final result.
        vector<int> ans;
        while (end_idx != -1) {
            ans.push_back(nums[end_idx]);
            end_idx = prev[end_idx];
        }
        return ans;
    }
};