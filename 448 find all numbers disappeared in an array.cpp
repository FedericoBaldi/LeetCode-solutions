// https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> missingNumbers;
        nums.push_back(nums.size()+1);
        nums.push_back(0);
        sort(nums.begin(), nums.end());
        for (int index = 0; index < nums.size()-1; index++){
            if (nums[index+1] - nums[index] > 1){
                for (int indexJ = nums[index]+1; indexJ < nums[index+1]; indexJ++){
                    missingNumbers.push_back(indexJ);
                }
            }
        }
        return missingNumbers;
    }
};