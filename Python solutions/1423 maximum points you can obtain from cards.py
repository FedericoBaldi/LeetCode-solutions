# https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards
# TC: o(n) SC: o(1)
class Solution:
    def maxScore(self, cardPoints: List[int], k: int) -> int:
        left_sum = 0
        for i in range(k):
            left_sum += cardPoints[i]
        
        right_sum = 0
        best = left_sum
        for i in range(k):
            left_sum -= cardPoints[k - i - 1]
            right_sum += cardPoints[len(cardPoints) - i - 1]
            best = max(best, right_sum + left_sum)
        return best

