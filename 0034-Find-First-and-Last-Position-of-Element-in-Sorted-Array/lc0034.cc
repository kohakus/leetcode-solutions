// C++ solution.

// Just binary search
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (!nums.empty()) {
            int pos = insert_pos(nums, target);
            if (pos < nums.size() && nums[pos] == target) {
                return {pos, insert_pos(nums, target+1)-1};
            }
        }
        return {-1, -1};
    }

    // like std::lower_bound, finding the first position of element that does not satisfy element < target
    int insert_pos(vector<int>& nums, int target) {
        int low = 0, high = nums.size();
        while (low < high) {
            int mid = low + ((high-low) >> 1);
            if (nums[mid] >= target) { high = mid; }
            else { low = mid+1; }
        }
        return low;
    }
};
