// https://leetcode.com/problems/flatten-binary-tree-to-linked-list
// TS:O(n) SC:O(1)
class Solution {
public:
    void flatten(TreeNode* root) {
        fTree (root, root);
    }
private:
    TreeNode* fTree(TreeNode* root, TreeNode* head) {
        if (root != NULL){
            TreeNode * rightNode = root->right;
            if (root != head){ 
                head->right = root;
                head = head->right;
            }
            head = fTree (root->left, head);
            root->left = NULL;
            head = fTree (rightNode, head);
        }
        return head;
    }
};