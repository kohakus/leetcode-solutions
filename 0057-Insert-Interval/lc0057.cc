// C++ solution.

// intervals are sorted, we can use binary search to find insert position
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if (newInterval.empty()) { return intervals; }
        auto comp = [] (const vector<int>& v1, const vector<int>& v2) {
            return v1.back() < v2.front();
        };
        auto erange = equal_range(intervals.cbegin(), intervals.cend(), newInterval, comp);

        vector<vector<int>> res;
        for (auto it = intervals.begin(); it != erange.first; it++) {
            res.push_back(*it);
        }

        if (erange.first == erange.second) {
            res.push_back(newInterval);
        } else {
            int overlap_start = min(erange.first -> front(), newInterval.front());
            int overlap_end = max((erange.second-1) -> back(), newInterval.back());
            res.push_back({overlap_start, overlap_end});
        }

        for (auto it = erange.second; it != intervals.end(); it++) {
            res.push_back(*it);
        }
        return res;
    }
};