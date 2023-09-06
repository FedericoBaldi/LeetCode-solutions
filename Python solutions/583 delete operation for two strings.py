# https://leetcode.com/problems/delete-operation-for-two-strings
# TC: o(n*m) SC: o(n*m)
# DP with indexes -> 2D
class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        @cache
        def helper(i, j):
            if i == len(word1) or j == len(word2):
                return len(word1) - i + len(word2) - j
            
            best = min(1 + helper(i + 1, j), 1 + helper(i, j + 1))
            
            if word1[i] == word2[j]:
                best = min(best, helper(i + 1, j + 1))
            return best
        return helper(0, 0)
