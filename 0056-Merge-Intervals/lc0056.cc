// C++ solution.

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end(),
             [](const vector<int>& a, const vector<int>& b) { return a[0] < b[0]; });
        if (intervals.size() > 0) {
            ans.push_back(intervals[0]);
            for (int i = 1; i < intervals.size(); i++) {
                if (intervals[i][0] > ans.back()[1]) {
                    ans.push_back(intervals[i]);
                } else {
                    ans.back()[1] = max(ans.back()[1], intervals[i][1]);
                }
            }
        }
        return ans;
    }
};
