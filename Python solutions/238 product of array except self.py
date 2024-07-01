# https://leetcode.com/problems/product-of-array-except-self
# TC: o(n) SC: o(1)
# Double pass loop
class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        prev = 1
        res = [1] * len(nums)
        for i in range(len(nums)):
            res[i] = res[i] * prev
            prev = prev * nums[i]
        prev = 1
        for i in range(len(nums) - 1, -1, -1):
            res[i] = res[i] * prev
            prev = prev * nums[i]
        return res