# Python solution.

class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        ans = []
        for pair in sorted(intervals, key=lambda x: x[0]):
            if ans and pair[0] <= ans[-1][1]:
                ans[-1][1] = max(ans[-1][1], pair[1])
            else:
                ans.append(pair[:])
        return ans
