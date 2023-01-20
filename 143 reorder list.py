# https://leetcode.com/problems/reorder-list
# iterative
# TC: O(n) SC: O(n/2)
class Solution:
    def reorderList(self, head: Optional[ListNode]) -> None:
        """
        Do not return anything, modify head in-place instead.
        """
        slow = head
        fast = slow
        stack = []
        while slow is not None:
            if fast is None or fast.next is None: 
                stack.append(slow)
            else:
                fast = fast.next.next
            slow = slow.next

        slow = head
        while stack:
            node = stack.pop()
            node.next = slow.next
            slow.next, slow = node, slow.next
            if stack == 1:
                node.next = None
        return head