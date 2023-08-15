// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree
// TS:O(logn) SC:O(1)
// use the property of a binary tree and that both nodes exist in the tree
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while (1){
            if (root->val > p->val && root->val > q->val) {
                root = root->left;
            }
            else if (root->val < p->val && root->val < q->val){
                root = root->right;
            }
            else {
                break;
            }
        }
        return root;
    }
};