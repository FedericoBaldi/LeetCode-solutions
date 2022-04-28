// https://leetcode.com/problems/minimum-number-of-operations-to-move-all-balls-to-each-box
// TC:O(n^2) SC:O(1)
class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> minOperations(boxes.size(), 0);
        for (int index = 0; index < boxes.size(); index++){
            for(int indexJ = 0; indexJ < boxes.size(); indexJ++){
                if (boxes[indexJ] == '1'){
                    minOperations[index] += abs(index - indexJ);
                }
            }
        }
        return minOperations;
    }
};