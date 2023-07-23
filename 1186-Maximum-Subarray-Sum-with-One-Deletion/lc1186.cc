// C++ solution.

// DP.
// Time complexity: O(N)
class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int dp_del = 0;
        int dp_undel = arr[0];
        int ans = arr[0];
        for (int i = 1; i < arr.size(); i++) {
            int num = arr[i];
            dp_del = std::max(dp_undel, dp_del+num);
            dp_undel = std::max(dp_undel, 0) + num;
            ans = std::max(ans, std::max(dp_del, dp_undel));
        }
        return ans;
    }
};