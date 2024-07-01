# https://leetcode.com/problems/reverse-nodes-in-k-group
# TC: o(n) SC: o(1)
# Find len and reverse by group, being carefull at connections
class Solution:
    def reverseKGroup(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        dummy = ListNode(next = head)
        listlen = 0
        while head:
            head = head.next
            listlen += 1
        head = dummy.next
        saved_first = head
        for i in range(listlen//k):
            prev = None
            saved_last = head
            for _ in range(k):
                head_new = head.next
                head.next = prev
                prev = head
                head = head_new
            if i == 0:
                dummy.next = prev
            else:
                saved_first.next = prev
                saved_first = saved_last
        saved_last.next = head
        return dummy.next