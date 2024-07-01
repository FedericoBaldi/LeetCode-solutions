# https://leetcode.com/problems/interleaving-string
# TC: o(n*m) SC: o(1)
# DP 2D
class Solution:
    def isInterleave(self, s1: str, s2: str, s3: str) -> bool:
        if len(s1) + len(s2) != len(s3):
            return False
        @cache
        def dfs(i, j):
            if i == len(s1) and j == len(s2):
                return True
            curr = i + j
            res = False
            if i < len(s1) and s1[i] == s3[curr]:
                res = res or dfs(i+1, j)
            if j < len(s2) and s2[j] == s3[curr]:
                res = res or dfs(i, j+1)
            return res
        return dfs(0, 0)