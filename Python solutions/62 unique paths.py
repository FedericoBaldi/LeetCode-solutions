# https://leetcode.com/problems/unique-paths
# TC: o(m* n) SC: o(m*n)
# DP top-down
class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        res = 0
        directions = [[1, 0], [0, 1]]

        @cache
        def dfs(i, j):
            if i >= m or j >= n:
                return 0
            if i == m-1 and j == n-1:
                return 1
            res = 0
            for direction in directions:
                res += dfs(i + direction[0], j + direction[1])
            return res
        return dfs(0, 0)

