// https://leetcode.com/problems/kth-smallest-element-in-a-bst
// TC:O(n) SC:O(1)
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int> numbers;
        fillVector(root, numbers);
        return numbers[k-1];
    }
private:
    void fillVector(TreeNode* root, vector<int> &vect){
        if (root != NULL){
            fillVector(root->left, vect);
            vect.push_back(root->val);
            fillVector(root->right, vect);
        }
    }
};