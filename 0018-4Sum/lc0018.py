# Python solution.

class Solution:
    def __init__(self):
        self.ans = []

    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        nums.sort()
        self.NSum(nums, target, 4, 0, [])
        return self.ans

    def NSum(self, nums: List[int], target: int, N: int, idx: int, res: List[int]) -> None:
        sz = len(nums) - idx
        if sz < N: return
        if N == 2:
            left, right = idx, idx+sz-1
            while left < right:
                s = nums[left] + nums[right]
                if s == target:
                    self.ans.append(res + [nums[left], nums[right]])
                    while left < right and nums[left] == nums[left+1]: left += 1
                    while left < right and nums[right] == nums[right-1]: right -= 1
                    left += 1
                    right -= 1
                elif s < target:
                    left += 1
                else:
                    right -= 1
        else:
            for i in range(idx, len(nums)-N+1):
                if i > idx and nums[i] == nums[i-1]: continue
                self.NSum(nums, target-nums[i], N-1, i+1, res+[nums[i]])
