# Pre-compute and sliding window
# TC: o(n*p) SC: o(n)
class Solution:
    def maxSatisfied(self, customers: List[int], grumpy: List[int], minutes: int) -> int:
        best = 0
        for i in range(len(customers)):
            if grumpy[i] == 0:
                best += customers[i]
        curr = best
        for i in range(len(customers)):
            if grumpy[i] == 1:
                curr += customers[i]
            if i >= minutes and grumpy[i-minutes] == 1:
                curr -= customers[i-minutes]
            best = max(best, curr)
        return best