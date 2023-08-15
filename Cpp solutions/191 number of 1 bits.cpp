// https://leetcode.com/problems/number-of-1-bits
// TS:O(logn) SC:O(1)
// faster. and logic operation with previous number to reduce significantly many cases.
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int nBits = 0;
        while (n){
            nBits ++;
            n &= (n-1);
        }
        return nBits;
    }
};
// TS:O(logn) SC:O(1)
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int nBits = 0;
        while (n){
            nBits += n % 2; 
            n = n / 2;
        }
        return nBits;
    }
};
// TS:O(logn) SC:O(1)
// get the most significant bit and use it as a divider to count the 1 bits.
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int nBits = 0;
        uint32_t divider = pow(2, floor(log2(n))); // most significant digit
        while (n){
            nBits += n / divider; 
            n = n % divider;
            divider /= 2;
        }
        return nBits;
    }
};