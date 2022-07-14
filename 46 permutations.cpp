// https://leetcode.com/problems/permutations
// TS:O(n!) SC:O(n!)
// backtracking approach adding the visited status.
class Solution {
private:
    vector<vector<int>> permutations;
    void dfs(vector<int>& nums, vector<int> &curr, vector<int> &visited){
        if (curr.size() == nums.size()){
            permutations.push_back(curr);
        }
        for (int index = 0; index < nums.size(); index++){
            if (visited[index] != 1){
                visited[index]= 1;
                curr.push_back(nums[index]);

                dfs(nums, curr, visited);

                curr.pop_back();
                visited[index] = -1;
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> visited(nums.size(), -1);
        vector<int> curr;
        dfs(nums, curr, visited);
        return permutations;
    }
};