// C++ solution.

// Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei),
// find the minimum number of conference rooms required.
//
// Example 1
// Input: intervals = [(0,30),(5,10),(15,20)]
// Output: 2
// Explanation:
// We need two meeting rooms
// room1: (0,30)
// room2: (5,10),(15,20)
//
// Example 2
// Input: intervals = [(2,7)]
// Output: 1
// Explanation:
// Only need one meeting room

/**
 * Definition of Interval:
 * classs Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

// In fact, the target is:
// to find the maximum number of intersected meetings that holding at a specific time.

// using map to hold ascending order by timeline naturally (Red-Black Tree).
class Solution {
public:
    int minMeetingRooms(vector<Interval> &intervals) {
        std::map<int, int> logger;
        for (Interval& interval : intervals) {
            ++logger[interval.start];
            --logger[interval.end];
        }
        int rooms = 0;
        int ans = 0;
        for (auto& it : logger) {
            rooms += it.second;
            ans = std::max(ans, rooms);
        }
        return ans;
    }
};

// sort by start time, and then,
// use min-heap to hold order by end time.
class Solution {
public:
    int minMeetingRooms(vector<Interval> &intervals) {
        std::sort(intervals.begin(), intervals.end(), [](const Interval& a, const Interval& b) { return a.start < b.start; });
        std::priority_queue<int, vector<int>, std::greater<int>> que;
        for (const auto& interval : intervals) {
            if (!que.empty() && que.top() < interval.start) {
                que.pop();
            }
            que.push(interval.end);
        }
        return que.size();
    }
};