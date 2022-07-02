// https://leetcode.com/problems/root-equals-sum-of-children
// TLE TS:O(1) SC:O(1)
class Solution {
public:
    bool checkTree(TreeNode* root) {
        return root->val == root->left->val + root->right->val;
    }
};

