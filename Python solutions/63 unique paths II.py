# https://leetcode.com/problems/unique-paths-ii
# TC: o(n^2) SC: o(n^2)
class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:
        directions = [(0,1), (1,0)]
        @cache
        def dfs(i, j):
            if i == len(obstacleGrid) - 1 and j == len(obstacleGrid[0]) - 1:
                return 1
            paths = 0
            for d in directions:
                x, y = i + d[0], j + d[1]
                if x >= 0 and x < len(obstacleGrid) and y >= 0 and y < len(obstacleGrid[0]) and obstacleGrid[x][y] != 1:
                    paths += dfs(x, y)
            return paths
        return dfs(0, 0)

