# https://leetcode.com/problems/kth-largest-element-in-a-stream
# init TC: o(n*logn) SC: o(n)
# add TC: o(logn) SC: o(n)
class KthLargest:
    def __init__(self, k: int, nums: List[int]):
        self.k = k
        self.heap = nums
        heapify(self.heap)
        while len(self.heap) > self.k:
            heappop(self.heap)

    def add(self, val: int) -> int:
        heappush(self.heap, val)
        if len(self.heap) > self.k:
            heappop(self.heap)
        return self.heap[0]