// C++ solution.


// bit manipulation
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int missing = nums.size();
        for (int i = 0; i < nums.size(); i++) {
            missing ^= i ^ nums[i];
        }
        return missing;
    }
};


// Arithmetic sequence
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int arr_sum = accumulate(nums.begin(), nums.end(), 0);
        int target_sum = nums.size() * (nums.size()+1) / 2;
        return target_sum - arr_sum;
    }
};