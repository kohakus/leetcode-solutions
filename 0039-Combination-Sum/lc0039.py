# Python solution.

class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        candidates.sort()
        ans, res = [], []

        def backtrack(cur: int, residual: int):
            if residual == 0:
                ans.append(res.copy())
            else:
                for i in range(cur, len(candidates)):
                    if residual >= candidates[i]:
                        res.append(candidates[i])
                        backtrack(i, residual-candidates[i])
                        res.pop()

        backtrack(0, target)
        return ans
