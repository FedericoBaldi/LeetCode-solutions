// https://leetcode.com/problems/sort-list
// bubble sort solution (TLE)
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        ListNode *currentHead = head;
        bool isSorted = false;
        while (isSorted == false){
            isSorted = true;
            ListNode *previousNode = NULL;
            while (head != NULL){
                ListNode *swapNode = head->next;
                
                if (swapNode != NULL && head->val > swapNode->val){
                    cout << head->val << " " << head << endl;
                    cout << swapNode->val << " " << swapNode << endl;
                    if (previousNode != NULL){
                        previousNode->next = swapNode;
                    }
                    if (currentHead == head){
                        currentHead = swapNode;
                    }
                    head->next = swapNode->next;
                    swapNode->next = head;
                    previousNode = swapNode;
                    isSorted = false;
                }
                else{
                    previousNode = head;
                    head = head->next;
                }
            }
            head = currentHead;
        }
        return currentHead;
    }
};

// top down merge sort(accepted)
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (head == NULL || head->next == NULL){
            return head;
        }
        ListNode* midNode = getMid(head); //top down merge sort
        ListNode* leftNode = sortList(head);
        ListNode* rightNode = sortList(midNode);
        return mergeLists(leftNode, rightNode);
    }
    
    ListNode* getMid(ListNode* head){
        ListNode *midNode = NULL;
        while (head != NULL && head->next != NULL){
            if (midNode == NULL){
                midNode = head;
            }
            else{
                midNode = midNode->next; //fast and slow
            }
            head = head->next->next;
        }
        ListNode *mid = midNode->next; //right side on the list
        midNode->next = NULL; //break the list
        return mid;
    }
    
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