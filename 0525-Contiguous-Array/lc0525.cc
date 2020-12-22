// C++ solution.

// prefix sum memorization
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        // mapping: prefix sum -> the first occurrence of the prefix sum
        unordered_map<int, int> hash;
        hash[0] = -1;
        int prefix_sum = 0;
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            prefix_sum += nums[i] == 1 ? 1 : -1;
            if (hash.find(prefix_sum) != hash.end()) {
                ans = std::max(ans, i - hash[prefix_sum]);
            } else {
                hash[prefix_sum] = i;
            }
        }
        return ans;
    }
};