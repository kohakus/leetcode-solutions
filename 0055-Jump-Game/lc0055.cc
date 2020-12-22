// C++ solution.

class Solution {
public:
  bool canJump(vector<int>& nums) {
    int expect = 0;
    for (int i = 0; i < nums.size(); i++) {
      if (i > expect) { return false; }
      expect = max(expect, i+nums[i]);
    }
    return true;
  }
};
