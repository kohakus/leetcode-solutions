// C++ solution.

class Solution {
public:
  vector<vector<int>> fourSum(vector<int>& nums, int target) {
    NSum(nums, target, 4);
    return ans;
  }

  void NSum(vector<int>& nums, int target, int N){
    res = vector<int>(N, 0);
    sort(nums.begin(), nums.end());
    NSolve(nums, target, N, 0, 0);
  }

  void NSolve(vector<int>& nums, int target, int N, int idx, int cursor) {
    int sz = nums.size()-idx;
    if (sz < N) return;
    if (N == 2){
      int left = idx, right = idx+sz-1;
      while (left < right) {
        if (nums[left]+nums[right] == target) {
          res[cursor] = nums[left];
          res[cursor+1] = nums[right];
          ans.push_back(res);
          while (left < right && nums[left] == nums[left+1]) left++;
          while (left < right && nums[right] == nums[right-1]) right--;
          left++; right--;
        } else if (nums[left]+nums[right] < target) {
          left++;
        } else {
          right--;
        }
      }
      return;
    }

    for (int i = idx; i < nums.size()-N+1; i++) {
      if (i > idx && nums[i] == nums[i-1]) continue;
      res[cursor] = nums[i];
      NSolve(nums, target-nums[i], N-1, i+1, cursor+1);
    }
  }

private:
  vector<int> res;
  vector<vector<int>> ans;
};
