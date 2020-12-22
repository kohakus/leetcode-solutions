// C++ solution.

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if (nums.empty()) { return {}; }
        vector<string> ans;
        int start = nums[0];
        int end = start;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i-1] + 1 == nums[i]) {
                end = nums[i];
            } else {
                string range = start == end ? to_string(start) : to_string(start) + "->" + to_string(end);
                ans.push_back(std::move(range));
                start = nums[i];
                end = start;
            }
        }
        string range = start == end ? to_string(start) : to_string(start) + "->" + to_string(end);
        ans.push_back(std::move(range));
        return ans;
    }
};