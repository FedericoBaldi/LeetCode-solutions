// https://leetcode.com/problems/next-permutation
// TS:O(n) SC:O(1)
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int index = nums.size() - 1;
        while (index > 0  && nums[index] <= nums[index - 1]){ // find index to swap
            index--;
        }
        for (int indexJ = index, indexK = nums.size() - 1; indexJ < indexK; indexJ++, indexK--){ // reverse from index
            swap(nums[indexJ], nums[indexK]);
        }

        if (index != 0){
            int indexJ = index - 1;
            while (nums[index] <= nums[indexJ]){
                index++;
            }
            swap(nums[indexJ], nums[index]);
        }
    }
};