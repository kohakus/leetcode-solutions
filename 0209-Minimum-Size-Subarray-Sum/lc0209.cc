// C++ solution.

// Two pointers. Sliding window.
// Time complexity: O(N).
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int posl = 0;
        int posr = 0;
        int n = nums.size();
        int subsum = 0;
        int ans = n+1;
        for (; posr < n; posr++) {
            subsum += nums[posr];
            while (subsum >= s) {
                ans = std::min(ans, posr-posl+1);
                subsum -= nums[posl++];
            }
        }
        return ans == n+1 ? 0 : ans;
    }
};

// Binary search.
// Time complexity: O(NlogN).
// Calculate the prefix sums, every two prefix sums corresponds to a contiguous subarray.
// For example:
// |.......................|
// |...........|
//             |...........|
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix_sums(n+1, 0);
        int ans = n+1;
        for (int i = 0; i < n; i++) {
            prefix_sums[i+1] = prefix_sums[i] + nums[i];
        }

        for (int posr = n; posr >= 0 && prefix_sums[posr] >= s; posr--) {
            int posl = upper_bound(prefix_sums.begin(),
                                   prefix_sums.begin() + posr,
                                   prefix_sums[posr] - s) - prefix_sums.begin();
            ans = std::min(ans, posr-posl+1);
        }
        return ans == n+1 ? 0 : ans;
    }
};