// C++ solution.

// simple O(N^2) DP
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        size_t n = nums.size();
        if (n < 2) {
            return n;
        }
        int ans = 1;
        vector<int> dp(n, 1);
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j]+1);
                }
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};

// Robinson-Schensted-Knuth Algorithm O(NlogN)
// Note that RSK algorithm cannot give you an actual LIS
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> incvec;
        for (int num : nums) {
            auto it = lower_bound(incvec.begin(), incvec.end(), num);
            if (it != incvec.end()) {
                *it = num;
            } else {
                incvec.push_back(num);
            }
        }
        return incvec.size();
    }
};