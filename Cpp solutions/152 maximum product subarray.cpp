// https://leetcode.com/problems/maximum-product-subarray
// TS:O(n) SC:O(1)
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxProd = 1;
        int minProd = 1;
        int best = nums[0];
        for (int index = 0; index < nums.size(); index++){
            if (nums[index] < 0){
                int temp = minProd;
                minProd = maxProd;
                maxProd = temp;
            }
            minProd = minProd * nums[index];
            maxProd = maxProd * nums[index];
            if (minProd > nums[index]){
                minProd = nums[index];
            }
            if (maxProd < nums[index]){
                maxProd = nums[index];
            }
            if (best < maxProd){
                best = maxProd;
            }
        }
        return best;
    }
};
