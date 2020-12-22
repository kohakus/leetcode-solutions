# Python solution.

class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        poslog = {}
        start, ans = (0, 0)
        for cursor, val in enumerate(s):
            query_pos = poslog.get(val)
            start = max(start, query_pos if query_pos else 0)
            ans = max(ans, cursor-start+1)
            poslog[val] = cursor+1
        return ans
