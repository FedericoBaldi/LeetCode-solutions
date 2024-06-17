# Sliding window while keeping track of zero positions to move the start point
# TC: o(n) SC: o(1)
class Solution:
    def longestOnes(self, nums: List[int], k: int) -> int:
        zeros_pos = deque()
        start = 0
        best = 0
        for end in range(len(nums)):
            if nums[end] == 0:
                zeros_pos.append(end)
                if len(zeros_pos) - 1 == k:
                    start = zeros_pos.popleft() + 1
            best = max(end - start + 1, best)
        return best