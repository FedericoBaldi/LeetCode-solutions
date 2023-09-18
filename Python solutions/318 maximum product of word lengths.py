# https://leetcode.com/problems/maximum-product-of-word-lengths
# TC: o(n^2) SC: o(n) k = number of sums
class Solution:
    def maxProduct(self, words: List[str]) -> int:
        count = []
        for w in words:
            count.append(set(w))
        best = 0
        for i in range(len(count)):
            for j in range(i + 1, len(count)):
                if not count[i] & count[j]:
                    best = max(best, len(words[i]) * len(words[j]))
        return best
