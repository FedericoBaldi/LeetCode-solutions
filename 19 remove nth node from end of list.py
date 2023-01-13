# https://leetcode.com/problems/remove-nth-node-from-end-of-list
# TC: O(n) SC: O(1)
class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        front = head
        while front is not None and n > 0:
            front = front.next
            n -= 1
        dummy = ListNode(0, head)
        prev = dummy
        while front is not None:
            front = front.next
            prev = prev.next
        prev.next = prev.next.next
        return dummy.next