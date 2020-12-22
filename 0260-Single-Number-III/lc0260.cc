// C++ solution.

// Time complexity: O(N), Space complexity: O(1).
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        // the first pass: get the XOR of a and b.
        int diff = accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());
        // get the lowest bits, use it as the feature to distinguish a and b.
        diff &= -diff;

        // the second pass: find a and b.
        vector<int> ans{0, 0};
        for (int num : nums) {
            if (num & diff) {
                ans[0] ^= num;
            } else {
                ans[1] ^= num;
            }
        }
        return ans;
    }
};