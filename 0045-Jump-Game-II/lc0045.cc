// C++ solution.

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) { return 0; }
        int expect = nums[0], anchor = nums[0], step = 0;
        for (int i = 1; i < n; i++) {
            if (i > anchor) {
                anchor = expect;
                step++;
            }
            expect = max(expect, i+nums[i]);
        }
        return step+1;
    }
};
