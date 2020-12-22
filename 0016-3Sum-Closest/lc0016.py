# Python solution.

class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        nums.sort()
        sz = len(nums)
        best_match, min_diff = 0, 2147483647
        for i in range(sz-2):
            if i > 0 and nums[i] == nums[i-1]: continue
            left, right = i+1, sz-1
            while left < right:
                sums = nums[i] + nums[left] + nums[right]
                diff = abs(sums-target)
                if diff == 0: return target
                if diff < min_diff:
                    min_diff = diff
                    best_match = sums
                if sums > target: right -= 1
                else: left += 1
        return best_match
