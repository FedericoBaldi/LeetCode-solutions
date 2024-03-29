// https://leetcode.com/problems/add-two-numbers
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *dummyHead = new ListNode();
        ListNode *node = dummyHead;
        int sum = 0;
        while (l1 != NULL || l2 != NULL || sum != 0){
            if (l1 != NULL){
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2 != NULL){
                sum += l2->val;
                l2 = l2->next;
            }
            node->next = new ListNode(sum % 10);
            sum = sum / 10;
            node = node->next;
        }
        return dummyHead->next;
    }
};