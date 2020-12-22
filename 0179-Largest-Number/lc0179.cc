// C++ solution.

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        std::vector<std::string> num_strs;
        std::transform(nums.begin(), nums.end(), std::back_inserter(num_strs),
                    [](int num) { return std::to_string(num); });
        std::sort(num_strs.begin(), num_strs.end(),
                    [](std::string& lhs, std::string& rhs) { return lhs+rhs > rhs+lhs; });

        std::string ans;
        for (std::string& str : num_strs) {
            if (str == "0" && ans.empty()) { continue; }
            ans += str;
        }
        return ans.empty() ? "0" : ans;
    }
};