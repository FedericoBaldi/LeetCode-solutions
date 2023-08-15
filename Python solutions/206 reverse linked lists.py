# https://leetcode.com/problems/reverse-linked-list
# iterative
# TC: O(n) SC: O(1)
class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        node = head
        prev = None
        while node is not None:
            next_node = node.next
            node.next = prev
            prev = node
            node = next_node
        return prev
# recursive
# TC: O(n) SC: O(n)
class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head is None:
            return None

        new_head = head
        if head.next is not None:
            new_head = self.reverseList(head.next)
            head.next.next = head
        head.next = None
        return new_head