// https://leetcode.com/problems/merge-k-sorted-lists
// TS:O(nlogn) SC:O(1) n = sum of all linked list sizes
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode * head = NULL;
        ListNode * lastNode = NULL;
        for (int index = 0; index < lists.size(); index++){
            ListNode * node = lists[index];
            if (node != NULL){
                if (lastNode != NULL){
                    lastNode->next = node;
                }
                if (head == NULL){
                    head = node;
                }
                while (node->next != NULL){
                    node = node->next;
                }
                lastNode = node;
            }
        }
        head = sortLinkedList(head);
        return head;
    }
private:
    ListNode* sortLinkedList(ListNode* head){
        if (head == NULL || head->next == NULL){
            return head;
        }
        ListNode * mid = getMid(head);
        ListNode * left = sortLinkedList(head);
        ListNode * right = sortLinkedList(mid);
        return mergeLinkedList(left, right);
    }
    ListNode * getMid(ListNode* head){
        ListNode *fast = head;
        while (fast == NULL && fast->next == NULL){
            head = head->next;
            fast = fast->next->next;
        }
        ListNode * mid = head->next; // mid + 1
        head->next = NULL; // break the list
        return mid;
    }
    ListNode * mergeLinkedList(ListNode *first, ListNode *second){ //maybe I could use directly mergeLinkedList knowing they are sorted
        ListNode fakeHead(0);
        ListNode *node = &fakeHead;
        while (first != NULL || second != NULL){
            if (second == NULL || (first != NULL && first->val < second->val)){
                node->next = first;
                first = first->next;
            }
            else {
                node->next = second;
                second = second->next;
            }
            node = node->next;
        }
        return fakeHead.next;
    }
};