// https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii
// TC: O(n) SC: O(1)
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* node = head;
        ListNode* previousNode;
        ListNode* previousNode2 = NULL;
        bool isDuplicate = false;
        while (node != NULL && node->next != NULL){
            previousNode = node;
            node = node->next;
            if (previousNode->val == node->val){
                isDuplicate = true;
            }
            else if (isDuplicate == true){
                if (previousNode2 == NULL){
                    head = node;
                }
                else{
                    previousNode2->next = node;
                }
                isDuplicate = false;
            }
            else{
                previousNode2 = previousNode;
            }
        }
        if (isDuplicate == true){ // handling edge cases
            if (previousNode2 != NULL){
                previousNode2->next = NULL;
            }
            else{
                head = NULL;
            }
        }
        return head;
    }
};