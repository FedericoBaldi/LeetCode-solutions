# https://leetcode.com/problems/valid-parenthesis-string
# TC: o(n) SC: o(1)
# Greedy
class Solution:
    def checkValidString(self, s: str) -> bool:
        cmin = 0
        cmax = 0
        for c in s:
            if c == '(':
                cmax += 1
                cmin += 1
            elif c == ')':
                cmax -= 1
                cmin = max(cmin-1, 0)
            else:
                cmax += 1
                cmin = max(cmin - 1, 0)
            if cmax < 0:
                return False
        return cmin == 0

