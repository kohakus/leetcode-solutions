// C++ solution.

// DP.
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) { return 0; }

        int ans = nums[0];
        int smax = nums[0], smin = nums[0];
        for (int i = 1; i < n; i++) {
            int curr = nums[i];
            if (curr < 0) { swap(smax, smin); }
            smax = max(curr, curr*smax);
            smin = min(curr, curr*smin);
            ans = max(smax, ans);
        }
        return ans;
    }
};