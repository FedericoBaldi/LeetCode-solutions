# TC: o(n*logn) SC: o(n)
class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        heap = []
        for n in nums:
            heappush(heap, -n)
        for _ in range(k-1):
            heappop(heap)
        return -heappop(heap)