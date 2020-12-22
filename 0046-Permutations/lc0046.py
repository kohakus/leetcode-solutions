# Python solution.

class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        return reduce(lambda ll, x: [l[:i] + [x] + l[i:] for l in ll for i in range(len(l)+1)],
                      nums,
                      [[]])
