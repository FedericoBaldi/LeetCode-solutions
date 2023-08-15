// https://leetcode.com/problems/increasing-order-search-tree
// TC:O(n) SC:O(n)
class Solution {
public:
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode fakeHead(0);
        if (root != NULL){
            flattenInOrder(root, &fakeHead);
        }
        return fakeHead.right;
    }
private:
    TreeNode* flattenInOrder(TreeNode* root, TreeNode* head) {
        if (root != NULL){
            head = flattenInOrder(root->left, head);
            head->right = new TreeNode(root->val);
            head = head->right;
            head = flattenInOrder(root->right, head);
        }
        return head;
    }
};