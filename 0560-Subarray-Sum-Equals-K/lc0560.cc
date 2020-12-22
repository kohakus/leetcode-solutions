// C++ solution.

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefix_n;
        int cur_acc = 0;
        int ans = 0;

        prefix_n.insert({0, 1});
        for (int num : nums) {
            cur_acc += num;
            auto it = prefix_n.find(cur_acc - k);
            if (it != prefix_n.end()) {
                ans += it->second;
            }
            ++prefix_n[cur_acc];
        }
        return ans;
    }
};