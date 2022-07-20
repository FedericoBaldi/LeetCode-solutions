// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree
// TS:O(n) SC:O(n)
// sort of backtrack the 2 nodes.
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root){
            if (root == p || root == q){
                return root;
            }
            
            TreeNode* left = lowestCommonAncestor(root->left, p, q);
            TreeNode* right = lowestCommonAncestor(root->right, p, q);
            if (right && left){
                return root;
            }
            else if (right){
                return right;
            }
            else {
                return left; // it can be NULL
            }
        }
        return NULL;
    }
};