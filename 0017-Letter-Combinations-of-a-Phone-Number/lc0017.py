# Python solution.

class Solution:
    def __init__(self):
        self.dig = ["", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"]
        self.ans = []
        self.res = []

    def letterCombinations(self, digits: str) -> List[str]:
        sz = len(digits)
        self.digits = digits
        if sz > 0:
            self.res = ['0' for i in range(sz)]
            self.backtracking(0, sz)
        return self.ans

    def backtracking(self, depth: int, sz: int) -> None:
        if depth == sz:
            self.ans.append("".join(self.res))
            return

        button = int(self.digits[depth])
        for letter in self.dig[button]:
            self.res[depth] = letter
            self.backtracking(depth+1, sz)
