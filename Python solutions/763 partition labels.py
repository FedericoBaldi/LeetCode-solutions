# https://leetcode.com/problems/partition-labels
# TC: o(n) SC: o(n) 
# Greedy. Find the cut if current is the last char
class Solution:
    def partitionLabels(self, s: str) -> List[int]:
        res = []
        position_last = {}
        for i in range(len(s)):
            position_last[s[i]] = i
        start = 0
        until = 0
        for i in range(len(s)):
            until = max(until, position_last[s[i]])
            if i == until:
                res.append(i + 1 - start)
                start = i + 1
                until = i + 1
        return res

# Convert to intervals and merge
# TC: o(nlogn) SC: o(n)
class Solution:
    def partitionLabels2(self, s: str) -> List[int]:
        intervals = {}
        for i in range(len(s)):
            if s[i] in intervals:
                intervals[s[i]][1] = i
            else:
                intervals[s[i]] = [i, i]
        intr = list(intervals.values())
        intr.sort()
        new_intr = [intr[0]]
        for i in range(1, len(intr)):
            if new_intr[-1][1] >= intr[i][0]:
                new_intr[-1][1] = max(new_intr[-1][1], intr[i][1])
            else:
                new_intr.append(intr[i])
        res = []
        for start, end in new_intr:
            res.append(end - start + 1)
        return res