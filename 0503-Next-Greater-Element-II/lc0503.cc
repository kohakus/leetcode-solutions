// C++ solution.

// monostack, loop twice.
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        // monostack to maintain a decreasing sequence, storing indices.
        stack<int> monostack;
        vector<int> ans(n, -1);
        for (int i = 0; i < 2*n; i++) {
            int num = nums[i%n];
            while (!monostack.empty() && nums[monostack.top()] < num) {
                ans[monostack.top()] = num;
                monostack.pop();
            }
            if (i < n) {
                monostack.push(i);
            }
        }
        return ans;
    }
};