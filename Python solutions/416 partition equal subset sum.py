# https://leetcode.com/problems/partition-equal-subset-sum
# TC: o(n*sum) SC: o(n*sum) 
# DFS DP
class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        goal = sum(nums) / 2
        @cache
        def dfs(i, curr):
            if curr == goal:
                return True
            if curr > goal or i == len(nums):
                return False
            return dfs(i+1, curr + nums[i]) or dfs(i+1, curr)
        return dfs(0, 0)