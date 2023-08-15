// https://leetcode.com/problems/combination-sum
// TS:O(2^t) SC:O(1) t = target
// backtrack - keep trying any possibility in an ordered way call 2 times. 1 to go on to the next index, and 2 same index and apply same concept until over target or reach target
class Solution {
private:
    vector<vector<int>> combinations;
    void dfs(vector<int>& candidates, int target, int index, vector<int> &current, int total){
        if (total == target){
            combinations.push_back(current);
        }
        else if (index < candidates.size() && total < target){
            current.push_back(candidates[index]);
            dfs(candidates, target, index, current, total + candidates[index]);
            current.pop_back();
            dfs(candidates, target, ++index, current, total);
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> current;
        dfs(candidates, target, 0, current, 0);
        return combinations;
    }
};