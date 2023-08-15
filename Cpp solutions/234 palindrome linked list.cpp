// https://leetcode.com/problems/palindrome-linked-list
// TC:O(n) SC:O(n)
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode *slow = head;
        ListNode *fast = head;
        vector<int> first;
        while (fast != NULL && fast->next != NULL){
            first.push_back(slow->val);
            slow = slow->next;
            fast = fast->next->next;
        }
        if (fast != NULL){
            slow = slow->next;
        }
        while (slow != NULL){
            if (first.back() != slow->val){
                return false;
            }
            first.pop_back();
            slow = slow->next;
        }
        return true;
    }
};