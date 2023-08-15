# https://leetcode.com/problems/frequency-of-the-most-frequent-element
# TC: O(log(n)n))) SC: O(1)
class Solution:
    def maxFrequency(self, nums: List[int], k: int) -> int:
        nums.sort()
        start = 0
        stop = 1
        buffer = k
        curr_sum = nums[0]
        while stop < len(nums):
            curr_sum += nums[stop]
            if nums[stop] * (stop - start + 1) - curr_sum > k: # slide condition
                curr_sum -= nums[start]
                start += 1
            stop += 1
        return stop - start