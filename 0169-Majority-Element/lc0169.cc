// C++ solution.

// Moore Voting.
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt = 0;
        int ans;
        for (int num : nums) {
            if (!cnt) {
                // update the current majority
                ans = num;
            }
            num == ans ? ++cnt : --cnt;
        }
        return ans;
    }
};

// Hash table.
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, size_t> cnts;
        for (int num : nums) {
            if (++cnts[num] > nums.size() >> 1) {
                return num;
            }
        }
        return 0;
    }
};