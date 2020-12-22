// C++ solution.

class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        // mapping: num -> (first_pos, degree)
        unordered_map<int, pair<int, int>> logger;
        int max_degree = 0;
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            auto query = logger.find(nums[i]);
            if (query == logger.end()) {
                logger[nums[i]] = make_pair(i, 1);
                if (!ans) { ans = 1; }
            } else {
                if (++query->second.second > max_degree) {
                    max_degree = query->second.second;
                    ans = i - query->second.first + 1;
                }
                if (query->second.second == max_degree) {
                    ans = std::min(ans, i - query->second.first + 1);
                }
            }
        }
        return ans;
    }
};