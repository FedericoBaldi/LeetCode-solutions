# https://leetcode.com/problems/unique-length-3-palindromic-subsequences
# TS: o(n) SC: o(1)
from collections import defaultdict
class Solution:
    def countPalindromicSubsequence(self, s: str) -> int:
        res = 0
        hashmap = {} # char - interval
        for i, c in enumerate(s):
            if c not in hashmap:
                hashmap[c] = []
                hashmap[c].extend([i,i])
            else:
                hashmap[c][1] = i
        
        for key, value in hashmap.items():
            used = set()
            l, r = value
            l += 1
            while l < r:
                if s[l] not in used:
                    res += 1
                    used.add(s[l])
                l += 1
        return res

    def countPalindromicSubsequence2(self, s: str) -> int:
        res = 0
        used = set()
        for index in range(len(s)-2):
            if s[index] in used:
                continue
            last_index = len(s) - 1
            used.add(s[index])
            while last_index - index >= 2 and s[index] != s[last_index]:
                last_index -= 1
            used_pal = set()
            while last_index - index >= 2:
                last_index -= 1
                if s[last_index] not in used_pal:
                    res += 1
                    used_pal.add(s[last_index])
        return res