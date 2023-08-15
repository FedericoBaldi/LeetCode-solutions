// https://leetcode.com/problems/search-in-rotated-sorted-array
// TS:O(logn) SC:O(1)
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while (left < right){
            int mid = left + (right - left) / 2;
            if (nums[mid] > nums[right]){
                left = mid + 1;
            }
            else{
                right = mid;
            }
        }
        int minP = left;
        right = nums.size() - 1;
        if (nums[minP] > target || nums[right] < target){
            left = 0;
            right = max(minP - 1, 0);
        }
        while (left <= right){
            int mid = left + (right - left) / 2;
            if (nums[mid] < target){
                left = mid + 1;
            }
            else if (nums[mid] > target){
                right = mid - 1;
            }
            else {
                return mid;
            }
        }
        return -1;
    }
};