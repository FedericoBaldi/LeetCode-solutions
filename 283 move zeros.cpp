// https://leetcode.com/problems/move-zeroes
// TC:O(n) SC:O(1)
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zeros = 0;
        for (int index = 0; index < nums.size(); index++){
            if (nums[index] == 0){
                zeros++;
                nums.erase(nums.begin()+index);
                index--;
            }
        }
        for (int index = 0; index < zeros; index++){
            nums.push_back(0);
        }
    }
};