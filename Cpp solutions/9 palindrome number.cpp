// https://leetcode.com/problems/palindrome-number
class Solution {
public:
    bool isPalindrome(int x) {
        bool isPal = false;
        int number = x;
        uint reverse = 0;
        do {
            int digit = number % 10;
            reverse = (reverse * 10) + digit;
            number = number / 10;
        }while(number != 0);
        if (x >= 0 && x == reverse){
            isPal = true;
        }
        return isPal;
    }
};