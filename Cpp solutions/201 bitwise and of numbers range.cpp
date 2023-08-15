// https://leetcode.com/problems/bitwise-and-of-numbers-range
// TS:O(logn) SC:O(1)
class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        while (right > left){
            right &= right - 1; //remove the rightermost bit
        }
        return right;
    }
};