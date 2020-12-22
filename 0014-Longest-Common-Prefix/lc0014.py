# Python solution.

class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        if len(strs) == 0:
            return ""
        for i in range(len(strs[0])):
            if any(i == len(strv) or strs[0][i] != strv[i] for strv in strs[1:]):
                return strs[0][:i]
        return strs[0]
