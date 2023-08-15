// https://leetcode.com/problems/linked-list-cycle
// fast and slow pointers
class Solution {
public:
    bool hasCycle(ListNode *head) {
        bool cycle = false;
        ListNode * slow = head;
        ListNode * fast = head;
        while (cycle == false && fast != NULL && fast->next != NULL){
            slow = slow ->next;
            fast = fast->next->next;
            if (slow == fast){
                cycle = true;
            }
        }
        return cycle;
    }
};
// map solution, not so fast
class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_map<ListNode *, int> valuesMap;
        bool cycle = false;
        while (cycle == false && head != NULL){
            if (valuesMap[head] == 0){
                valuesMap[head] = 1;
            }
            else {
                cycle = true;
            }
            head = head->next;
        }
        return cycle;
    }
};