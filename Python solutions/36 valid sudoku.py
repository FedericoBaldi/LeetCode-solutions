# https://leetcode.com/problems/valid-sudoku
# TC: o(n^2) SC: o(n)
class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        map_board = defaultdict(set)
        for row in range(len(board)):
            for col in range(len(board[0])):
                n = board[row][col]
                if n == ".":
                    continue
                if n in map_board[(0, row)]:
                    return False
                if n in map_board[(1, col)]:
                    return False
                if n in map_board[(2, row // 3, col // 3)]:
                    return False
                map_board[(0, row)].add(n)
                map_board[(1, col)].add(n)
                map_board[(2, row // 3, col // 3)].add(n)
        return True