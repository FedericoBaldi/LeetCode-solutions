# https://leetcode.com/problems/coin-change
# TC: o(n^2) SC: o(a) a = amount
class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        @cache
        def dfs(curr):
            if curr < 0:
                return float("inf")
            if curr == 0:
                return 0
            best = float("inf")
            for c in coins:
                best = min(best, dfs(curr - c) + 1)
            return best
        return dfs(amount) if dfs(amount) != float("inf") else -1
