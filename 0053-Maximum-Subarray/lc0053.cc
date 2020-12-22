// C++ solution.

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