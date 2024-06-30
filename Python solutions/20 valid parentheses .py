# https://leetcode.com/problems/valid-parentheses
# TC: o(n) SC: o(n)
# Stack
class Solution:
    def isValid(self, s: str) -> bool:
        stack = []

        for c in s:
            if c == '(' or c == '[' or c == '{':
                stack.append(c)
            elif stack:
                par = stack.pop()
                if (c == ')' and par != '(') or (c == ']' and par != '[') or (c == '}' and par != '{'):
                    return False
            else:
                return False
        return True if len(stack) == 0 else False

