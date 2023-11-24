# https://leetcode.com/problems/combination-sum
# TC: o(2^n), SC: o(n)
# You can do it with shift as well.
class Solution:
    def findDifferentBinaryString(self, nums: List[str]) -> str:
        res = []
        numbers = set()
        for i in range(len(nums)):
            numb = 0
            for j in range(len(nums[0]) -1, -1, -1):
                if nums[i][j] == '1':
                    numb += pow(2, abs(j - len(nums[0]) + 1))
            numbers.add(numb)
        
        k = 0
        while k <= len(nums):
            if k not in numbers:
                for _ in range(len(nums)):
                    if k > 0:
                        if k % 2 == 1:
                            res.append('1')
                        else:
                            res.append('0')
                        k = k // 2
                    else:
                        res.append('0')
                return "".join(reversed(res))
            k += 1
        return ""
