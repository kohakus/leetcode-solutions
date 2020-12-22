# Python solution.

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        hash = {}
        for k, v in enumerate(nums):
            if hash.get(target - v) != None:
                return [hash[target-v], k]
            hash[v] = k
        return []
