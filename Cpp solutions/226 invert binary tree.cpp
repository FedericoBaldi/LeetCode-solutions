// https://leetcode.com/problems/invert-binary-tree
// TC:O(n) SC:O(1)
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root != NULL){
            TreeNode *temp = root->left;
            root->left = root->right;
            root->right = temp;
            invertTree(root->left);
            invertTree(root->right);
        }
        return root;
    }
};