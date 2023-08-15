# https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii
# TC: O(n) SC: O(1)
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        profit = 0
        stock = prices[0]
        for price in prices:
            if price > stock:
                profit += price - stock
            stock = price
        return profit