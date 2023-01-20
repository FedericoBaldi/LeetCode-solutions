# https://leetcode.com/problems/add-two-numbers
# TC: O(n) SC: O(n)
from math import fmod
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        dummy = ListNode()
        curr = dummy
        carry = 0
        while l1 is not None or l2 is not None or carry != 0:
            val1 = 0
            val2 = 0
            if l1 is not None:
                val1 = l1.val
                l1 = l1.next
            if l2 is not None:
                val2 = l2.val
                l2 = l2.next
            sum_val = val1 + val2 + carry
            carry = sum_val // 10
            curr.next = ListNode(int(fmod(sum_val, 10)))
            curr = curr.next

        return dummy.next