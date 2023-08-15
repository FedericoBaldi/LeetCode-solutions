// https://leetcode.com/problems/missing-number
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int missingNumber = 0;
        int sumNumbers = 0;
        for (int index = 0; index < nums.size(); index++){
            missingNumber += nums[index];
            sumNumbers += index;
        }
        sumNumbers += nums.size();
        missingNumber = sumNumbers - missingNumber;
        return missingNumber;
    }
};