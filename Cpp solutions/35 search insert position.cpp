// https://leetcode.com/problems/search-insert-position
// TS:O(logn) SC:O(1)
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size()-1;
        while (left <= right){
            int mid = left + (right - left) / 2;
            cout << mid << " ";
            if (target > nums[mid]){
                left = mid+1;
            }
            else{
                right = mid-1;
            }
        }
        if (left == nums.size() - 1 && nums[left] < target){
            left++;
        }
        return left;
    }
};