# Python solution.

class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if numRows == 1: return s
        ret = [''] * min(len(s), numRows)
        rowCursor = 0
        trigger = False

        for c in s:
            ret[rowCursor] += c
            rowCursor += -1 if trigger else 1
            if rowCursor == 0 or rowCursor == numRows-1:
                trigger = not trigger

        return ''.join(ret)
