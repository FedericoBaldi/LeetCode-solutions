// https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal
// TS:O(nm) SC:O(1)
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        TreeNode * head = new TreeNode(postorder.back());
        int index = 0;
        while (inorder[index] != postorder.back() && index < inorder.size()){
            index++;
        }
        postorder.pop_back();
        vector<int> leftBranch(inorder.begin(), inorder.begin() + index);
        vector<int> rightBranch(inorder.begin() + index + 1, inorder.end());
        postorder = buildTree(rightBranch, postorder, head, true);
        buildTree(leftBranch, postorder, head, false);
        return head;
    }
private:
    vector<int> buildTree(vector<int>& inorder, vector<int>& postorder, TreeNode* head, bool isRight){
        if (postorder.size() > 0 && inorder.size() > 0){
            int newHead = postorder.back();
            if (isRight){
                head->right = new TreeNode(newHead);
                head = head->right;
            }
            else{
                head->left = new TreeNode(newHead);
                head = head->left;
            }
            postorder.pop_back();
            int index = 0;
            while (inorder[index] != newHead && index < inorder.size()){
                index++;
            }
            vector<int> leftBranch(inorder.begin(), inorder.begin() + index);
            vector<int> rightBranch(inorder.begin() + index + 1, inorder.end());
            postorder = buildTree(rightBranch, postorder, head, true);
            postorder = buildTree(leftBranch, postorder, head, false);
        }
        return postorder;
    }
};