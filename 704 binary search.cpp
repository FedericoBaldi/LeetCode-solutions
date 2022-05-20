// https://leetcode.com/problems/binary-search
// TS:O(n) SC:O(1) 
// Standard binary search. Array need to be sorted.
// Start from the middle and decrease or increase the range at every iteration to narrow down the search.
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size()-1;
        while (left <= right){
            int mid = left + (right - left) / 2;
            if (nums[mid] < target){
                left = mid + 1;
            }
            else if(nums[mid] > target){
                right = mid - 1;
            }
            else {
                return mid;
            }
        }
        return -1;
    }
};