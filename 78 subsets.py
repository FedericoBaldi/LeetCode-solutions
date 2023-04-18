# TC: o(2^n * n) SC: o(2^n * n)
class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        res = []
        sset = []
        def helper(index: int):
            if index >= len(nums):
                res.append(sset[:])
                return
            sset.append(nums[index])
            helper(index + 1)
            sset.pop()
            helper(index + 1)
        helper(0)
        return res