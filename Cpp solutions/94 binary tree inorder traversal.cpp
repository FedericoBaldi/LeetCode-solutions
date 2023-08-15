// https://leetcode.com/problems/binary-tree-inorder-traversal
// TS:O(n) SC:O(n)
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> tree;
        if (root){
            tree = inorderTraversal(root->left);
            tree.push_back(root->val);
            vector<int> sup = inorderTraversal(root->right);
            tree.insert(tree.end(), sup.begin(), sup.end());
        }
        return tree;
    }
};