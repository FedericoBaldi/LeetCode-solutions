// https://leetcode.com/problems/plus-one
// TC:O(n) SC:O(1)
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        bool carry = true;
        int index = digits.size()-1;
        while (index >= 0 && carry == true){
            if (digits[index] == 9){
                digits[index] = 0;
            }
            else{
                digits[index]++;
                carry = false;
            }
            index--;
        }
        if (carry){
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};