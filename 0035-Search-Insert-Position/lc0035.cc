// C++ solution.

// just use STL.
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        return std::lower_bound(nums.begin(), nums.end(), target) - nums.begin();
    }
};

// standard binary search.
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }
};