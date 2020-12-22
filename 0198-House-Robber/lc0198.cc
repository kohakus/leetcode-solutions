// C++ solution.

// DP. Time: O(N), Sapce: O(N)
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty()) { return 0; }
        vector<int> dp(nums.size(), 0);
        for (int i = 0; i < nums.size(); i++) {
            if (i == 0) {
                dp[0] = nums[0];
            } else if (i == 1) {
                dp[1] = max(dp[0], nums[1]);
            } else {
                dp[i] = max(dp[i-2] + nums[i], dp[i-1]);
            }
        }
        return dp[nums.size()-1];
    }
};

// DP. Time: O(N), Space: O(1)
// We need not to store all states.
class Solution {
public:
    int rob(vector<int>& nums) {
        int cur = 0, pre = 0;
        for (int i = 0; i < nums.size(); i++) {
            int temp = max(pre + nums[i], cur);
            pre = cur;
            cur = temp;
        }
        return cur;
    }
};