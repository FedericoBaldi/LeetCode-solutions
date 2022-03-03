// https://leetcode.com/problems/arithmetic-slices
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int subArrays = 0;
        if (nums.size() < 3){
            return 0;
        }
        for (int index = 0; index < nums.size()-2; index++){
            int diff = nums[index+1] - nums[index];
            for (int indexJ = index+2; indexJ < nums.size(); indexJ++){
                if (nums[indexJ] - nums[indexJ-1] == diff){
                    subArrays++;
                }
                else{
                    break;
                }
            }
        }
        return subArrays;
    }
};