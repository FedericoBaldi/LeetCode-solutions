// https://leetcode.com/problems/remove-linked-list-elements
// TC: O(n) SC: O(1)
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* node = head;
        ListNode* prev = NULL;
        while (node != NULL){
            if (node->val == val){
                if (prev != NULL){
                    prev->next = node->next;
                }
                else{
                    head = node->next;
                }
            }
            else{
               prev = node;
            }
            node = node->next;
        }
        return head;
    }
};