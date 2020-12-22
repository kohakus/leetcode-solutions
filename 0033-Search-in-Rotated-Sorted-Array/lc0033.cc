// C++ solution.

// Use binary search directly.
class Solution {
public:
    int search(vector<int>& nums, int target) {
        auto adjust = [&](int x) -> int {
            if (target < nums[0]) {
                return x < nums[0] ? x : numeric_limits<int>::min();
            } else {
                return x < nums[0] ? numeric_limits<int>::max() : x;
            }
        };

        int low = 0;
        int high = nums.size();
        while (low < high) {
            int mid = low + (high-low) / 2;
            int mid_val = adjust(nums[mid]);
            if (mid_val > target) {
                high = mid;
            } else if (mid_val < target) {
                low = mid + 1;
            } else {
                return mid;
            }
        }
        return -1;
    }
};

// FP style.
class Solution {
public:
    int search(vector<int>& nums, int target) {
        auto skip_left = [&](int x) -> int { return x >= nums[0] ? numeric_limits<int>::min() : x; };
        auto skip_right = [&](int x) -> int { return x < nums[0] ? numeric_limits<int>::max() : x; };
        auto adjust = [&](int x) -> int { return target < nums[0] ? skip_left(x) : skip_right(x); };
        auto comp = [&](int x, int y) -> bool { return adjust(x) < adjust(y); };
        auto it = lower_bound(nums.begin(), nums.end(), target, comp);
        return (it != nums.end() && *it == target) ? it-nums.begin() : -1;
    }
};