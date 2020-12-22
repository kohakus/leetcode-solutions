# Python solution.

class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        ssize, psize = len(s), len(p)
        dp = [[False for i in range(psize+1)] for j in range(ssize+1)]
        dp[ssize][psize] = True

        for i in range(ssize+1)[::-1]:
            for j in range(psize)[::-1]:
                firstMatch = (i < ssize) and (s[i] == p[j] or p[j] == '.')
                if j+1 < psize and p[j+1] == '*':
                    dp[i][j] = dp[i][j+2] or (firstMatch and dp[i+1][j])
                else:
                    dp[i][j] = firstMatch and dp[i+1][j+1]

        return dp[0][0]
