# Python solution.

class Solution:
    def search(self, nums: List[int], target: int) -> int:
        low, high = 0, len(nums)
        while low < high:
            mid = (low + high) // 2
            if (target < nums[0]) == (nums[mid] < nums[0]):
                num = nums[mid]
            else:
                num = -2147483648 if target < nums[0] else 2147483647

            if num == target:
                return mid
            elif num < target:
                low = low+1
            else:
                high = mid
        return -1
