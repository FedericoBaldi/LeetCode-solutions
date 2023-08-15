// https://leetcode.com/problems/balanced-binary-tree
// TS:O(n^2) SC:O(1)
// simple approache, check the heights of left and right and go down the tree. It can be improved.
class Solution {
private:
    int heightTree(TreeNode* root){
       int heightLeft = 0;
       int heightRight = 0;
       if (root){
           heightLeft = heightTree(root->left);
           heightRight =  heightTree(root->right);
       }
       return max(heightLeft, heightRight) + 1;
    }
public:
    bool isBalanced(TreeNode* root) {
        bool balanced = true;
        if (root){
            balanced &= abs(heightTree(root->left) - heightTree(root->right)) <= 1;
            balanced &= isBalanced(root->left);
            balanced &= isBalanced(root->right);
        }
        return balanced;
    }
};