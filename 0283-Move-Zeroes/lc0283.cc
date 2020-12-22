// C++ solution.

// Two pointers.
// Time: O(N), Space: O(1).
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int setpos = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                nums[setpos++] = nums[i];
            }
        }
        while (setpos < nums.size()) {
            nums[setpos++] = 0;
        }
    }
};

// Two pointers. (Optimization)
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int setpos = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                swap(nums[setpos++], nums[i]);
            }
        }
    }
};