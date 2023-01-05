// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted
// TC:O(n) SC:O(1)
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        for (int index = 0, indexBack = numbers.size() - 1; index < numbers.size() && indexBack >= 0;){
            if (target > numbers[index] + numbers[indexBack]){
                index++;
            }
            else if (target < numbers[index] + numbers[indexBack]){
                indexBack--;
            }
            else {
                return {index + 1, indexBack + 1};
            }
        }
        return {0, 0};
    }
};