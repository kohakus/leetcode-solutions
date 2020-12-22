# Python solution.

class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        if len(nums) == 0:
            return [-1, -1]
        else:
            pos = self.insert_pos(nums, target)
            if pos < len(nums) and nums[pos] == target:
                return [pos, self.insert_pos(nums, target+1)-1]
        return [-1, -1]

    def insert_pos(self, nums: List[int], target: int):
        (low, high) = (0, len(nums))
        while low < high:
            mid = low + (high-low)//2
            if nums[mid] >= target:
                high = mid
            else:
                low = mid + 1
        return low
