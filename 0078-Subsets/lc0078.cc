// C++ solution.

class Solution {
public:
  vector<vector<int>> subsets(vector<int>& nums) {
    int n = 1 << nums.size();
    vector<vector<int>> ans(n, vector<int>());
    for (int i = 0; i < n; i++) {
      for (int p = nums.size()-1; p >= 0; p--) {
        if ((i >> p) & 1) {
          ans[i].push_back(nums[p]);
        }
      }
    }
    return ans;
  }
};
