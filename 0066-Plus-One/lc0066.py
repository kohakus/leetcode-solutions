# Python solution.

class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        if digits == []:
            return [1]
        else:
            t = digits[-1] + 1
            if t < 10:
                return digits[:-1] + [t]
            else:
                return self.plusOne(digits[:-1]) + [0]
