# https://leetcode.com/problems/permutation-in-string
# TC: o(n) SC: o(1)
# Double counter of 26 and match it with a sliding window
class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        if len(s1) > len(s2):
            return False

        count1 = [0] * 26
        count2 = [0] * 26
        for i in range(len(s1)):
            count1[ord(s1[i]) - ord('a')] += 1
            count2[ord(s2[i]) - ord('a')] += 1
        
        matches = 0
        for i in range(len(count1)):
            if count1[i] == count2[i]:
                matches += 1
        left = 0
        for right in range(len(s1), len(s2)):
            if matches == 26:
                return True

            ileft = ord(s2[left]) - ord('a')
            iright = ord(s2[right]) - ord('a')
            
            count2[iright] += 1
            if count2[iright] == count1[iright]:
                matches += 1
            if count2[iright] == count1[iright] + 1:
                matches -= 1

            count2[ileft] -= 1
            if count2[ileft] == count1[ileft]:
                matches += 1
            if count2[ileft] == count1[ileft] - 1:
                matches -= 1
            left += 1
        return matches == 26