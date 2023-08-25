# https://leetcode.com/problems/reordered-power-of-2
# TC: o(log2(n)*o(9)) SC: o(9)
class Solution:
    def reorderedPowerOf2(self, n: int) -> bool:
        n = Counter(str(n))
        two = 1
        power = Counter(str(two))
        
        while sum(power.values()) <= sum(n.values()): # or for i in range(len(30)) constrain 10^9
            if power == n:
                return True
            two = two * 2
            power = Counter(str(two))
        return False
