# https://leetcode.com/problems/letter-combinations-of-a-phone-number
# TC: o(4^n) SC: o(n) n = len of digits
# Backtracking
class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        mapping = {'2': ['a','b','c'], '3': ['d','e','f'], '4': ['g','h','i'], '5': ['j','k','l'],
                    '6': ['m','n','o'], '7': ['p','q','r', 's'], '8': ['t','u','v'], '9': ['w','x','y','z']}
        if not digits:
            return digits
        res = set()
        curr = []
        def helper(index):
            if len(curr) == len(digits):
                res.add("".join(curr))
                return
            for c in mapping[digits[index]]:
                curr.append(c)
                helper(index + 1)
                curr.pop()
        helper(0)
        return res

