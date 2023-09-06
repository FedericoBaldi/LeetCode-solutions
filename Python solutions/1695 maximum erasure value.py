# https://leetcode.com/problems/maximum-erasure-value
# TC: o(n) SC: o(n)
class Solution:
    def maximumUniqueSubarray(self, nums: List[int]) -> int:
        start = 0
        curr = 0
        max_s = 0
        values = set()
        for end in range(len(nums)):
            while nums[end] in values:
                curr -= nums[start]
                values.remove(nums[start])
                start += 1
            curr += nums[end]
            values.add(nums[end])
            max_s = max(max_s, curr)
        return max_s

