// C++ solution.

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) {
            return n == 0 ? 0 : nums[0];
        }
        return std::max(_helper(nums, 0, n-2), _helper(nums, 1, n-1));
    }

private:
    int _helper(vector<int>& nums, const int l, const int r) {
        int pre = 0;
        int cur = 0;
        for (int i = l; i <= r; i++) {
            int temp = std::max(cur, nums[i] + pre);
            pre = cur;
            cur = temp;
        }
        return cur;
    }
};