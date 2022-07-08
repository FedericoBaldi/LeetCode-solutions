// https://leetcode.com/problems/validate-binary-search-tree
// TS:O(n) SC:O(n)
// find a way to check the condition. In this case it was enough to flatten the tree and check if the values were one already in order or not.
class Solution {
private:
    vector<int> treeFlattened;
    void fillQueue(TreeNode* root){
        if (root){
            fillQueue(root->left);
            treeFlattened.push_back(root->val);
            fillQueue(root->right);
        }
    }
public:
    bool isValidBST(TreeNode* root){
        bool isValid = true;
        fillQueue(root);
        for (int index = 1; index < treeFlattened.size() && isValid; index++){
            if (treeFlattened[index-1] >= treeFlattened[index]){
                isValid = false;
            }
        }
        return isValid;
    }
};