// https://leetcode.com/problems/binary-gap
// TS:O(logn) SC:O(1)
class Solution {
public:
    int binaryGap(int n) {
        int longestDist = 0;
        int currentDist = 0;
        while (n > 0){
            if (n % 2 == 1){
                longestDist = max(currentDist, longestDist);
                currentDist = 1;
            }
            else{
                if (currentDist > 0){
                   currentDist++; 
                }
            }
            n /= 2;
        }
        return longestDist;
    }
};

