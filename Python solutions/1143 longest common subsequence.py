# https://leetcode.com/problems/longest-common-subsequence
# TC: o(n*m) SC: o(n*m)
# DP 2D, you can even do it bottom up and be a little faster.
class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        @cache
        def dfs(i, j):
            if i == len(text1) or j == len(text2):
                return 0

            if text1[i] == text2[j]:
                return dfs(i+1, j+1) + 1
            return max(dfs(i, j+1), dfs(i+1, j))
        return dfs(0, 0)