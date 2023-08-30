# https://leetcode.com/problems/minimum-replacements-to-sort-the-array
# TC: o(n), SC:o(1)
# greedy
class Solution:
    def minimumReplacement(self, nums: List[int]) -> int:
        res = 0
        right_min = nums[len(nums) - 1]
        for i in range(len(nums) - 2, -1, -1):
            if nums[i] > right_min:
                num_elements = math.ceil(nums[i] / right_min)
                res += num_elements - 1
                right_min = nums[i] // num_elements
            else:
                right_min = nums[i]
        return res
