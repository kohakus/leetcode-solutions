// C++ solution.

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<int64_t> window;
        for (int i = 0; i < nums.size(); i++) {
            int64_t num = static_cast<int64_t>(nums[i]);
            auto it = window.lower_bound(num - t);
            if (it != window.end() && *it - num <= t) {
                return true;
            }
            window.insert(nums[i]);
            if (i >= k) {
                window.erase(nums[i-k]);
            }
        }
        return false;
    }
};