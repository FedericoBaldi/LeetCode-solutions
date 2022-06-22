// https://leetcode.com/problems/count-equal-and-divisible-pairs-in-an-array
// TC:O(n^2) SC:O(1)
class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        int pairs = 0;
        for (int index = 0; index < nums.size(); index++){
            for (int indexJ = index + 1; indexJ < nums.size(); indexJ++){
                if (nums[index] == nums[indexJ] && (index * indexJ) % k == 0){
                    pairs++;
                }
            }
        }
        return pairs;
    }
};