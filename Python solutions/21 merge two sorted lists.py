# https://leetcode.com/problems/merge-two-sorted-lists
# TC: o(n+m) SC: o(1)
# Iterative solution
class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        dummy = ListNode()
        prev = dummy
        while list1 and list2:
            if list1.val < list2.val:
                prev.next = list1
                list1 = list1.next
            else:
                prev.next = list2
                list2 = list2.next
            prev = prev.next

        if list1 is None:
            prev.next = list2
        else:
            prev.next = list1
        return dummy.next