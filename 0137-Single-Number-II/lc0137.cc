// C++ solution.

// an easy to understand solution.
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int> mask(32, 0);
        for (int i = 0; i < 32; i++) {
            for (int num : nums) {
                mask[i] += (num >> i) & 1;
            }
        }
        int ans = 0;
        for (int i = 0; i < 32; i++) {
            ans |= (mask[i] % 3) << i;
        }
        return ans;
    }
};