// https://leetcode.com/problems/binary-tree-level-order-traversal
// TS:O(n) SC:O(n)
// DFS using queue
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> nodeQueue;
        vector<vector<int>> result;
        if (root) nodeQueue.push(root);
        while (!nodeQueue.empty()){
            int n = nodeQueue.size();
            vector<int> levelV;
            while (n--){
                TreeNode* node = nodeQueue.front();
                nodeQueue.pop();
                levelV.push_back(node->val);
                if (node->left) nodeQueue.push(node->left);
                if (node->right) nodeQueue.push(node->right);
            }
            result.push_back(levelV);
        }
        return result;
    }
};