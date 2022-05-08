// https://leetcode.com/problems/first-bad-version
// TC:O(logn) SC:O(1)
class Solution {
public:
    int firstBadVersion(int n) {
        int left = 1;
        int right = n;
        while (left <= right){
            int mid = left + (right - mid) / 2;
            if (isBadVersion(mid) == false){
                if (isBadVersion(mid + 1) == true){
                    return mid + 1;
                }
                else{
                    left = mid + 1;
                }
            }
            else {
                right = mid - 1;
            }
        }
        return n;
    }
};