# https://leetcode.com/problems/group-anagrams
# TC: o(n*max(s)) SC: o(n*max(s))
class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        res = defaultdict(list)
        for i in range(len(strs)):
            freq = [0] * 26
            for c in strs[i]:
                freq[ord(c) - ord('a')] += 1
            res[tuple(freq)].append(strs[i])
        return res.values()

