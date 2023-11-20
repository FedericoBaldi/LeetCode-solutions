# https://leetcode.com/problems/longest-turbulent-subarray
# TC: o(2^n)~o(n+1) SC: o(n)
# Sliding window or napsack dfs
class Solution:
    def maxTurbulenceSize(self, arr: List[int]) -> int:
        best = 1
        start = 0
        start2 = 0
        for stop in range(1, len(arr)):
            if stop % 2 == 0:
                if arr[stop] >= arr[stop - 1]:
                    start = stop
                if arr[stop] <= arr[stop - 1]:
                    start2 = stop
            else:
                if arr[stop] <= arr[stop - 1]:
                    start = stop
                if arr[stop] >= arr[stop - 1]:
                    start2 = stop
            best = max(best, stop - start + 1, stop - start2 + 1)
        
        return best

