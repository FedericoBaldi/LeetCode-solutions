# https://leetcode.com/problems/last-stone-weight
# TC: o(n*log(n)) SC: o(n)
class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        max_heap = []
        for n in stones:
            heappush(max_heap, -n)
        while len(max_heap) > 1:
            first = heappop(max_heap)
            second = heappop(max_heap)
            if first != second:
                heappush(max_heap, first - second)
        return -max_heap[0] if max_heap else 0

