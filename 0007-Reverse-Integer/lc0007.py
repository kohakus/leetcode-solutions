# Python solution.

class Solution:
    def reverse(self, x: int) -> int:
        ret = 0
        while x != 0:
            # note that the behavior of '%' in Python is different from C/C++
            pop = int(math.fmod(x, 10))
            x = int(x/10)
            if ret > 214748364 or (ret == 214748364 and pop > 7): return 0
            if ret < -214748364 or (ret == -214748364 and pop < -8): return 0
            ret = ret * 10 + pop
        return ret
