// https://leetcode.com/problems/rotate-list
// TC: O(n) SC: O(1)
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL){
            return head;
        }
        ListNode *node = head;
        int listSize = 0;
        while (node->next != NULL){
            listSize++;
            node = node->next;
        }
        listSize++;
        k = k % listSize;
        node->next = head;
        
        node = head;
        for (int index = 0; index < listSize - k - 1; index++){
            node = node->next;
        }
        head = node->next;
        node->next = NULL;
        return head;
    }
};
// faster with map TC: O(n) SC: O(n)
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        unordered_map<int, ListNode*> listMap;
        if (head == NULL){
            return head;
        }
        ListNode *node = head;
        int listSize = 0;
        while (node != NULL){
            listMap[listSize] = node;
            listSize++;
            node = node->next;
        }
        k = k % listSize;
        
        if (k != 0){
            (listMap[listSize - 1])->next = head;
            head = listMap[listSize - k];
            (listMap[listSize - k - 1])->next = NULL;
        }
        return head;
    }
};