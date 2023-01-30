# https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree
# TC: O(log(n)) SC: O(h)
from collections import deque
class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        queue = deque()
        queue.append((root, 0))
        level_order = []
        while queue:
            curr = queue.popleft()
            if curr[0] is None:
                continue
            queue.append((curr[0].left, curr[1] + 1))
            queue.append((curr[0].right, curr[1] + 1))
            if len(level_order) <= curr[1]:
                level_order.append([])
            level_order[curr[1]].append(curr[0].val)
        return level_order