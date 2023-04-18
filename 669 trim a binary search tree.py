# TC: o(n) SC: o(1)
# you return the good nodes to keep
class Solution:
    def trimBST(self, root: Optional[TreeNode], low: int, high: int) -> Optional[TreeNode]:
        if root is None:
            return None
        if root.val < low:
            return self.trimBST(root.right, low, high)
        if root.val > high:
            return self.trimBST(root.left, low, high)
            
        root.left = self.trimBST(root.left, low, high)
        root.right = self.trimBST(root.right, low, high)
        return root
        
# helper solution, same complexity but dirty, you need to keep the prev and direction
class Solution:
    def trimBST(self, root: Optional[TreeNode], low: int, high: int) -> Optional[TreeNode]:
        dummy = TreeNode()
        dummy.right = root
        def helper(node: Optional[TreeNode], prev: Optional[TreeNode], direction: bool):
            if node is None:
                return
            sub = None
            if node.val < low:
                sub = node.right
            elif node.val > high:
                sub = node.left
            else:
                helper(node.left, node, 0)
                helper(node.right, node, 1)
                return
            
            if sub is not None:
                node.val, node.left, node.right = sub.val, sub.left, sub.right
                helper(node, prev, direction)
            else:
                if direction:
                    prev.right = None
                else:
                    prev.left = None

        helper(root, dummy, 1)
        return dummy.right