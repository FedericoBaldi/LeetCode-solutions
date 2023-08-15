// https://leetcode.com/problems/middle-of-the-linked-list
// fast and slow TC: O(n) SC: O(1)
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast != NULL && fast->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
};
// classic TC: O(n) SC: O(1)
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode *node = head;
        int size = 0;
        while (node != NULL){
            size++;
            node = node->next;
        }
        node = head;
        int index = 0;
        size = size / 2;
        while (index < size){
            node = node->next;
            index++;
        }
        return node;
    }
};