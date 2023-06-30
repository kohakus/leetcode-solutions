// C++ solution.

// Dutch national flag problem
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int l = 0, m = 0, h = nums.size()-1;
        while (m <= h) {
            if (nums[m] < 1) {
                swap(nums[l++], nums[m++]);
            } else if (nums[m] > 1) {
                swap(nums[m], nums[h--]);
            } else { m++; }
        }
    }
};
