// https://leetcode.com/problems/path-sum
// single map TS: O(n) SC: O(1) 
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        bool isFound = false;
        if (root != NULL){
            if (root->left != NULL){
                isFound |= hasPathSum(root->left, targetSum - root->val);
            }
            if(root->right != NULL){
                isFound |= hasPathSum(root->right, targetSum - root->val);
            }
            else if (root->left == NULL && targetSum - root->val == 0){
                isFound = true;
            }
        }
        return isFound;
    }
};