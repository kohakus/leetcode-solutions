# Python solution.

# Finite-state machine method (Discuss solution)
class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        transfer = {}
        state = 0

        # construct state transfer
        for c in p:
            if c == '*':
                transfer[state, c] = state
            else:
                transfer[state, c] = state+1
                state += 1

        # searching all possible states
        acc_state = state
        states = set([0])
        for c in s:
            states = set([transfer.get((state, token)) for state in states for token in [c, '*', '?']])

        return acc_state in states
