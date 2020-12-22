// C++ solution.

// Two pointers.
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if (nums.size() < 3) { return 0; }
        int ans = 0;
        int min_diff = numeric_limits<int>::max();

        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size()-2; i++) {
            if (i > 0 && nums[i] == nums[i-1]) { continue; }
            int left = i + 1;
            int right = nums.size() - 1;
            while (left < right) {
                int sum_three = nums[i] + nums[left] + nums[right];
                int diff = abs(sum_three - target);
                if (diff == 0) {
                    return sum_three;
                }
                if (diff < min_diff) {
                    min_diff = diff;
                    ans = sum_three;
                }
                if (sum_three > target) {
                    right--;
                } else {
                    left++;
                }
            }
        }
        return ans;
    }
};