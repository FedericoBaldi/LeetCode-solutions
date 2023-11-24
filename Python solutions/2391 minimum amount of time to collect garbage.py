# https://leetcode.com/problems/minimum-amount-of-time-to-collect-garbage
# TC: o(n*m), SC: o(1) n = len(garbage), m = len(max(garbage[i]))
class Solution:
    def garbageCollection(self, garbage: List[str], travel: List[int]) -> int:
        res = 0
        travel_cost = 0
        max_m = 0
        max_p = 0
        max_g = 0
        for i in range(len(garbage)):
            for j in range(len(garbage[i])):
                if garbage[i][j] == 'M':
                    max_m = travel_cost
                elif garbage[i][j] == 'P':
                    max_p = travel_cost
                else:
                    max_g = travel_cost
            res += len(garbage[i])
            if i < len(travel):
                travel_cost += travel[i]
        res += max_m + max_p + max_g
        return res
