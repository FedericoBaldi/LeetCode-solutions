# https://leetcode.com/problems/swim-in-rising-water
# TC: o(n*m*log(n*m)) SC: o(n*m)
# Dijkstra
class Solution:
    def swimInWater(self, grid: List[List[int]]) -> int:
        directions = [[1,0],[0,1],[-1,0],[0,-1]]
        heap = []
        heappush(heap,[grid[0][0],0,0])
        t = 0
        visited = set()
        while heap:
            cell = heappop(heap)
            t = cell[0]
            if cell[1] == len(grid) - 1 and cell[2] == len(grid[0]) - 1:
                return t
            for d in directions:
                nexti = cell[1] + d[0]
                nextj = cell[2] + d[1]
                if nexti >= len(grid) or nextj >= len(grid[0]) or nexti < 0 or nextj < 0 or (nexti, nextj) in visited:
                    continue
                nextt = max(t, grid[nexti][nextj])
                heappush(heap, [nextt, nexti, nextj])
                visited.add((nexti, nextj))
        return t
