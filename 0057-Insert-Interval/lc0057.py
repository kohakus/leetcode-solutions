# Python solution.

class Solution:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        s, e = newInterval
        lstl, lstr = [], []

        for l, r in intervals:
            if s > r:
                lstl += [[l, r]]
            elif e < l:
                lstr += [[l, r]]
            else:
                s, e = min(s, l), max(e, r)

        return lstl + [[s, e]] + lstr
