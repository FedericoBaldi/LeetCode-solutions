// https://leetcode.com/problems/search-a-2d-matrix/
// TC: O(log(m*n)) SC: O(1)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int low = 0;
        int high = matrix.size() - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (matrix[mid][0] > target){
                high = mid - 1;
            }
            else if(matrix[mid][0] < target){
                low = mid + 1;
            }
            else {
                return true;
            }
        }
        if (high >= 0){
            int secondLow = 0;
            int secondHigh = matrix[0].size() - 1;
            while (secondLow <= secondHigh){
                int mid = secondLow + (secondHigh - secondLow) / 2;
                if (matrix[high][mid] > target){
                    secondHigh = mid - 1;
                }
                else if (matrix[high][mid] < target){
                    secondLow = mid + 1;
                }
                else {
                    return true;
                }
            }
        }
        return false;
    }
};