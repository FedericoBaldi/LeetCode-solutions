# https://leetcode.com/problems/diagonal-traverse-ii
# TC: o(n) SC: o(n) n = numbers in the matrix
class Solution:
    def findDiagonalOrder(self, nums: List[List[int]]) -> List[int]:
        res = []
        diagonals = defaultdict(list)
        for i in range(len(nums) -1, -1, -1):
            for j in range(len(nums[i])):
                diagonals[i+j].append(nums[i][j])

        diag = 0
        while diag in diagonals:
            for i in range(len(diagonals[diag])):
                res.append(diagonals[diag][i])
            diag += 1
            
        return res
        
# TC: o(n*m) SC: o(n) n = row, m = max column lenght
    def findDiagonalOrder2(self, nums: List[List[int]]) -> List[int]:
        res = []
        max_row = 0
        for i in range(len(nums)):
            max_row = max(max_row, len(nums[i]))
            for j in range(i, -1, -1):
                if i - j < len(nums[j]):
                    res.append(nums[j][i-j])

        for j in range(1, max_row):
            for i in range(len(nums) -1, -1, -1):
                if j + len(nums) - 1 - i < len(nums[i]):
                    res.append(nums[i][j + len(nums) - 1 - i])
        return res

