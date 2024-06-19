# https://leetcode.com/problems/coin-change-ii
# TC: o(a*n) SC: o(a*n)
# Top-down dfs dp
class Solution:
    def change(self, amount: int, coins: List[int]) -> int:
        @cache
        def dfs(curr, i):
            if curr > amount or i >= len(coins):
                return 0
            if curr == amount:
                return 1
            return dfs(curr+coins[i], i) + dfs(curr, i+1)
        return dfs(0, 0)

