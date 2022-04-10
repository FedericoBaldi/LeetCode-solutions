// https://leetcode.com/problems/remove-nth-node-from-end-of-list
// TS:O(n) SC:O(1)
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode * node = head;
        ListNode * toDeleteNode = head;
        ListNode * previousNode = head;
        while(node != NULL){
            if (n <= 0){ //it is assumed we have n <= size
                previousNode = toDeleteNode;
                toDeleteNode = toDeleteNode->next;
            }
            n--;
            node = node->next;
        }
        if (head == toDeleteNode){
            head = toDeleteNode->next;
        }
        else{
            previousNode->next = toDeleteNode->next;   
        }
        delete toDeleteNode;
        
        return head;
    }
};