# Python solution.

class Solution:
    def isValid(self, s: str) -> bool:
        st = []
        matchmap = {')':'(', '}':'{', ']':'['}
        for c in s:
            if c in matchmap:
                if len(st) == 0: return False
                if st.pop() != matchmap[c]: return False
            else:
                st.append(c)
        return st == []
