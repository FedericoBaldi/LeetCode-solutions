# https://leetcode.com/problems/binary-tree-right-side-view
# TC: o(n) SC: o(n) n = number of nodes
class Solution:
    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        right_view = []
        def helper(root: Optional[TreeNode], curr_depth: int):
            if root is None:
                return
            curr_depth += 1
            if curr_depth > len(right_view):
                right_view.append(root.val)
            helper(root.right, curr_depth)
            helper(root.left, curr_depth)
        helper(root, 0)
        return right_view