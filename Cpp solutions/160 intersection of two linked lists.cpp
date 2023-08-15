// https://leetcode.com/problems/intersection-of-two-linked-lists
// TS:O(n) SC:O(1)
// use 2 pointers and run trough the lists, when they reach the end, reset to the other list head and go trough it again
// they will of the same length and you will find the intersection or they will arrive at NULL together.
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *firstPointer = headA;
        ListNode *secondPointer = headB;
        
        while (firstPointer != secondPointer){
            if (firstPointer){
                firstPointer = firstPointer->next;
            }
            else{
                firstPointer = headB;
            }
            
            if (secondPointer){
                secondPointer = secondPointer->next;
            }
            else{
                secondPointer = headA;
            }
        }
        return firstPointer;
    }
};