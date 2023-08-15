# https://leetcode.com/problems/search-a-2d-matrix
# TC: O(logn) SC: O(1)
class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        low = 0
        high = len(matrix) * len(matrix[0]) - 1
        while low <= high:
            mid = low + (high - low) // 2
            index_i = mid // len(matrix[0])
            index_j = mid % len(matrix[0])

            if matrix[index_i][index_j] < target:
                low = mid + 1
            elif matrix[index_i][index_j] > target:
                high = mid - 1
            else:
                return True
        return False