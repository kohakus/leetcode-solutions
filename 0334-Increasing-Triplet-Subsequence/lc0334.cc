// C++ solution.

// general thinking.
// Time complexity: O(N). Space complexity: O(1).
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        return checkIncreaseingSequenceLength(nums, nums.size(), 3);
    }

    bool checkIncreaseingSequenceLength(const vector<int>& nums, const int n, const int k) {
        if (n < k) {
            return false;
        }

        vector<int> seq;
        seq.reserve(k);
        seq.push_back(nums[0]);

        for (int i = 1; i < n; i++) {
            if (nums[i] > seq.back()) {
                seq.push_back(nums[i]);
                if (seq.size() >= k) {
                    return true;
                }
            }
            *lower_bound(seq.begin(), seq.end(), nums[i]) = nums[i];
        }
        return false;
    }
};


// clean code by fixing k = 3.
// Time complexity: O(N). Space complexity: O(1).
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int val1 = numeric_limits<int>::max();
        int val2 = numeric_limits<int>::max();
        for (int num : nums) {
            if (num <= val1) {
                val1 = num;
            } else if (num <= val2) {
                val2 = num;
            } else {
                return true;
            }
        }
        return false;
    }
};