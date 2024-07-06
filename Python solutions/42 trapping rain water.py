# https://leetcode.com/problems/combination-sum
# TC: o(n) SC: o(1)
# Double pass
class Solution:
    def trap(self, height: List[int]) -> int:
        water = 0
        start = 0
        curr = 0
        for i in range(1, len(height)):
            if height[start] <= height[i]:
                water += curr
                start = i
                curr = 0
            else:
                curr += height[start] - height[i]

        start = len(height) - 1
        curr = 0
        for i in range(len(height) - 2, -1, -1):
            if height[start] < height[i]:
                water += curr
                start = i
                curr = 0
            else:
                curr += height[start] - height[i]
        return water

