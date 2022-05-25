// https://leetcode.com/problems/same-tree
// TS:O(n) SC:O(1)
// recursively check if they are equal. start with p == q to assign true if they are both NULL.
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        bool isEqual = p == q;
        if (p != NULL && q != NULL){
            isEqual = p->val == q->val;
            isEqual = isEqual && isSameTree(p->left, q->left);
            isEqual = isEqual && isSameTree(p->right, q->right);
        }
        return isEqual;
    }
};