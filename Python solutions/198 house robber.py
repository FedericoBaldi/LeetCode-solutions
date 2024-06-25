# https://leetcode.com/problems/house-robber
# TC: o(n) SC: o(n)
# Rob or not rob, knapsack
class Solution:
    def rob(self, nums: List[int]) -> int:
        @cache
        def helper(i, robbed):
            if i >= len(nums):
                return 0

            go = helper(i+1, False)
            rob = 0
            if robbed is False:
                rob = helper(i+1, True) + nums[i]
            return max(go, rob)
        return helper(0, False)
        
# Greedy, you should always rob on a window of 3 houses
    def rob2(self, nums: List[int]) -> int:
        rob1, rob2 = 0, 0

        for n in nums:
            temp = max(n + rob1, rob2)
            rob1 = rob2
            rob2 = temp
        return rob2
