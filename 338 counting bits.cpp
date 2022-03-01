// https://leetcode.com/problems/counting-bits
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> bitesCount(n+1);
        bitesCount[0] = 0;
        // we use the previous calculated values and if the number is even
        for (int index = 1; index <= n; index++){
            bitesCount[index] = bitesCount[index / 2] + (index % 2);
        }
        return bitesCount;
    }
};