# https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree
# TC: o(logn) SC: o(h)
# Since we are sure we have the values in the tree we dont need to check edgecases
# We find the common ancestor by traversing in a bst way
def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
    if root.val > p.val and root.val > q.val:
        return self.lowestCommonAncestor(root.left, p, q)
    if root.val < p.val and root.val < q.val:
        return self.lowestCommonAncestor(root.right, p, q)
    return root
