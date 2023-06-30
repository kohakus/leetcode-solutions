// C++ solution.

// DP.
// Time complexity O(N)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = numeric_limits<int>::min();
        int dpval = 0;
        for (vector<int>::const_iterator it = nums.cbegin(); it != nums.cend(); it++) {
            dpval = max(*it + dpval, *it);
            ans = max(dpval, ans);
        }
        return ans;
    }
};

// Greedy.
// Time complexity O(N)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int subsum = 0;
        int ans = nums[0];
        for (vector<int>::const_iterator it = nums.cbegin(); it != nums.cend(); it++) {
            subsum += *it;
            ans = std::max(ans, subsum);
            if (subsum < 0) { subsum = 0; }
         }
        return ans;
    }
};