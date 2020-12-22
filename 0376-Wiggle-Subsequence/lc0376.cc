// C++ solution.

// Plain DP.
// Time complexity: O(N^2), Space complexity: O(N).
// Consider of element at position i as the last element in wiggle sequence.
// There are two possible valid substates:
//     the difference between the last two elements is positive or negative.
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int len = nums.size();
        if (len < 2) { return len; }
        vector<vector<int>> dp(len, vector<int>(2, 0));
        dp[0][0] = dp[0][1] = 1;
        int ans = 1;
        for (int i = 1; i < len; i++) {
            for (int j = i-1; j >= 0; j--) {
                if (nums[i] > nums[j]) {
                    dp[i][0] = max(dp[i][0], dp[j][1] + 1);
                }
                if (nums[i] < nums[j]) {
                    dp[i][1] = max(dp[i][1], dp[j][0] + 1);
                }
            }
            ans = max(ans, max(dp[i][0], dp[i][1]));
        }
        return ans;
    }
};

// Linear DP.
// Time complexity: O(N), Space complexity: O(N)/O(1).
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int len = nums.size();
        if (len < 2) { return len; }

        // up[i] is the length of a longest wiggle subsequence of {nums[0],...,nums[i]},
        // with a positive difference between its last two numbers.
        vector<int> up(len, 0);

        // down[i] is the length of a longest wiggle subsequence of {nums[0],...,nums[i]},
        // with a negative difference between its last two numbers.
        vector<int> down(len, 0);

        up[0] = down[0] = 1;
        for (int i = 1; i < len; i++) {
            if (nums[i] > nums[i-1]) {
                up[i] = down[i-1] + 1;
                down[i] = down[i-1];
            } else if (nums[i] < nums[i-1]) {
                up[i] = up[i-1];
                down[i] = up[i-1] + 1;
            } else {
                up[i] = up[i-1];
                down[i] = down[i-1];
            }
        }
        return max(up[len-1], down[len-1]);
    }
};

// Greedy.
// This problem is equivalent to finding the number of alternating max. and min. peaks in the array.
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int len = nums.size();
        if (len < 2) { return len; }
        int ans = 1;
        int sign = 0;
        for (int i = 1; i < len; i++) {
            // peak point (max peak)
            if (nums[i] < nums[i-1] && sign != -1) {
                sign = -1;
                ans++;
            }
            // valley point (min peak)
            if (nums[i] > nums[i-1] && sign != 1) {
                sign = 1;
                ans++;
            }
        }
        return ans;
    }
};