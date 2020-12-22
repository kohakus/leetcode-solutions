// C++ solution.

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        size_t pos = 0;
        for (int n : nums) {
            if (!pos || n != nums[pos-1]) {
                nums[pos++] = n;
            }
        }
        return pos;
    }
};