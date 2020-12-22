# Python solution.

class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        m = bisect.bisect(matrix, [target+0.5])
        if m:
            n = bisect.bisect(matrix[m-1], target)
            return len(matrix[0]) > 0 and matrix[m-1][n-1] == target
        return False
