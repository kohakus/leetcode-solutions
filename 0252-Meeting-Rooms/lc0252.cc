// C++ solution.

// Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei),
// determine if a person could attend all meetings.
//
// Note: (0,8),(8,10) is not conflict at 8.
//
// Example 1
// Input: intervals = [(0,30),(5,10),(15,20)]
// Output: false
// Explanation:
// (0,30), (5,10) and (0,30),(15,20) will conflict
//
// Example 2
// Input: intervals = [(5,8),(9,15)]
// Output: true
// Explanation:
// Two times will not conflict

/**
 * Definition of Interval:
 * class Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

// check if intervals are intersected.
class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const Interval& a, const Interval& b) { return a.start < b.start; });
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i].start < intervals[i-1].end) {
                return false;
            }
        }
        return true;
    }
};