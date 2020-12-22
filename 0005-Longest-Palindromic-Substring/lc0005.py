# Python solution.

class Solution:
    def longestPalindrome(self, s: str) -> str:
        if len(s) < 1: return ""
        start, end = (0, 0)
        for i in range(0, len(s)):
            curr_len = max(self.expand(s, i, i), self.expand(s, i, i+1))
            if curr_len > end-start:
                start = i - (curr_len-1)//2
                end = i + curr_len//2
        return s[start:end+1]

    def expand(self, s: str, left: int, right: int) -> int:
        while left >= 0 and right < len(s) and s[left] == s[right]:
            left = left - 1
            right = right + 1
        return right-left-1
