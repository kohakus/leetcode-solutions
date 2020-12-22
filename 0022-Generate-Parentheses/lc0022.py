# Python solution.

class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        ans = []

        def generate(left, right, s):
            if right == n:
                ans.append(s)
            if left < n:
                generate(left+1, right, s+"(")
            if right < left:
                generate(left, right+1, s+")")

        generate(0, 0, "")
        return ans
