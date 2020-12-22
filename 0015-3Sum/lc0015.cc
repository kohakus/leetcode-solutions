// C++ solution.

// Two pointers.
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        if (nums.size() < 3) { return ans; }

        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size()-2; i++) {
            if (i > 0 && nums[i] == nums[i-1]) {
                continue;
            }
            int left = i + 1;
            int right = nums.size() - 1;
            int target = 0 - nums[i];
            while (left < right) {
                int sum_two = nums[left] + nums[right];
                if (sum_two == target) {
                    ans.push_back({nums[i], nums[left], nums[right]});
                    while (left < right && nums[left] == nums[left+1]) { left++; }
                    while (left < right && nums[right] == nums[right-1]) { right--; }
                    left++;
                    right--;
                } else if (sum_two < target) {
                    left++;
                } else {
                    right--;
                }
            }
        }
        return ans;
    }
};