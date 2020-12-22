// C++ solution.

// naive memorization method. Time: O(N), Space: O(N)
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> fprods(n, 0);
        vector<int> bprods(n, 0);
        vector<int> ans(n, 0);

        // set dumb value.
        fprods[0] = 1;
        bprods[0] = 1;

        for (int i = 1; i < n; i++) {
            fprods[i] = fprods[i-1] * nums[i-1];
            bprods[i] = bprods[i-1] * nums[n-i];
        }

        for (int i = 0; i < n; i++) {
            ans[i] = fprods[i] * bprods[n-1-i];
        }
        return ans;
    }
};

// Time: O(N), Space: O(1)
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int fprod = 1;
        int bprod = 1;
        vector<int> ans(n, 1);

        for (int i = 0; i < n; i++) {
            ans[i]      *=  fprod;
            fprod       *=  nums[i];
            ans[n-1-i]  *=  bprod;
            bprod       *=  nums[n-1-i];
        }
        return ans;
    }
};