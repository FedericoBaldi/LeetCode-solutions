// https://leetcode.com/problems/merge-two-sorted-lists
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *head = NULL;
        if (list2 == NULL) {
            return list1;
        }
        else if (list1 == NULL) {
            return list2;
        }
        else if (list1->val >= list2->val) {
            head = new ListNode(list2->val);
            list2 = list2->next;
        }
        else {
            head = new ListNode(list1->val);
            list1 = list1->next;
        }
        ListNode *node;
        ListNode *previousNode = head;
        while (list1  != NULL || list2 != NULL) {
            if (list1 == NULL || (list2 != NULL && list1->val >= list2->val)){
                node = new ListNode(list2->val);
                list2 = list2->next;
            }
            else {
                node = new ListNode(list1->val);
                list1 = list1->next;
            }
            previousNode->next = node;
            previousNode = node;
        }
        return head;
    }
};

// better way
class SolutionV2 {
public:
	ListNode* mergeLists(ListNode *list1, ListNode* list2){
        ListNode* headMerge = new ListNode(0);
        ListNode* ptrList = headMerge;
        while (list1 != NULL || list2 != NULL){
            if (list1 == NULL || (list2 != NULL && list1->val >= list2->val)){
                ptrList->next = list2;
                list2 = list2->next;
            }
            else{
                ptrList->next = list1;
                list1 = list1->next;
            }
            ptrList = ptrList->next;
        }
        return headMerge->next;
   }
};