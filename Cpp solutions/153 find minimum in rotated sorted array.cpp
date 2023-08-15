// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array
// TS:O(logn) SC:O(1)
class Solution {
public:
    int findMin(vector<int>& nums) {
        int min;
        int left = 0;
        int right = nums.size() - 1;
        bool isFound = false;
        while (isFound == false){
            int mid = left + (right - left) / 2;
            int compare = mid - 1;
            if (mid == 0){
                compare = nums.size() - 1;
            }
            if (nums[compare] >= nums[mid]){
                min = nums[mid];
                isFound = true;
            }
            if (nums[mid] > nums[right]){
                left = mid + 1;
            }
            else{
                right = mid - 1;
            }
        }
        return min;
    }
};