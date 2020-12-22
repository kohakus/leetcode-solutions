// C++ solution.

// O(1) space
class Solution {
public:
  int firstMissingPositive(vector<int>& nums) {
    int n = nums.size();
    for (int i = 0; i < n; i++) {
      while (nums[i] > 0 && nums[i] <= n && nums[nums[i]-1] != nums[i]) {
        swap(nums[i], nums[nums[i]-1]);
      }
    }
    for (int i = 0; i < n; i++) {
      if (nums[i] != i+1) { return i+1; }
    }
    return n+1;
  }
};

// O(N) space
class Solution {
public:
  int firstMissingPositive(vector<int>& nums) {
    int n = nums.size();
    vector<bool> bucket(n+1, false);
    for (int i = 0; i < n; i++) {
      if (nums[i] > 0 && nums[i] <= n) {
        bucket[nums[i]] = true;
      }
    }
    for (int i = 1; i <= n; i++) {
      if (!bucket[i]) { return i; }
    }
    return n+1;
  }
};
