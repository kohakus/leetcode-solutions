// C++ Solution.

// Greedy.
class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int n = nums.size();
        bool is_modified = false;
        for (int i = 1; i < n; i++) {
            if (nums[i] >= nums[i-1]) {
                continue;
            }
            if (is_modified) {
                return false;
            }
            if (i-2 >= 0 && nums[i-2] > nums[i]) {
                nums[i] = nums[i-1];
            }
            is_modified = true;
        }
        return true;
    }
};