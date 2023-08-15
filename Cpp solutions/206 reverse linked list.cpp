// https://leetcode.com/problems/reverse-linked-list
// TS:O(n) SC:O(1)
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode * next;
        ListNode * prev = NULL;
        while (head != NULL){
            next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
};
// TS:O(n) SC:O(n)
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        stack<int> list;
        while (head != NULL){
            list.push(head->val);
            head = head->next;
        }
        ListNode fakeHead;
        ListNode *current = &fakeHead;
        while (!list.empty()){
            current->next = new ListNode(list.top());
            list.pop();
            current = current->next;
        }
        return fakeHead.next;
    }
};