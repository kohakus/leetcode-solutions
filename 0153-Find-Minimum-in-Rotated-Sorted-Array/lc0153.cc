// C++ solution.

// binary search method.
class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size()-1;

        // DO NOT use left <= right because that would loop forever
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > nums[right]) {
                // we know that the number at mid is greater than at least
                // one number to the right, so we can use mid + 1 and
                // never consider mid again; we know there is at least
                // one value smaller than it on the right.
                left = mid + 1;
            } else {
                // here, nums[mid] <= nums[right].
                // we KNOW the pivot must be at mid or to the left of mid.
                // we know it is possible for the mid index to store a smaller
                // value than at least one other index in the list (at right), so we do
                // not discard it by doing right = mid - 1. it still might have the minimum value.
                right = mid;
            }
        }
        return nums[left];
    }
};