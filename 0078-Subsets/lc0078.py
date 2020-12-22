# Python solution.

class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        n = 1 << len(nums)
        return [[num for p, num in enumerate(nums) if (i >> p) & 1] for i in range(n)]
