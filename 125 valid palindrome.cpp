// https://leetcode.com/problems/valid-palindrome
// TS:O(n) SC:O(1) 
// single cycle, double indexes. you skip or process the chars while going through it.
class Solution {
public:
    bool isPalindrome(string s) {
        bool isPalindrome = true;
        for (int index = 0, backIndex = s.size()-1; index < backIndex && isPalindrome; index++, backIndex--)
        {
            while (index < backIndex && (s[index] < 'a' || s[index] > 'z') && (s[index] < '0' || s[index] > '9') && (s[index] < 'A' || s[index] > 'Z')){
                index++;
            }
            while (index < backIndex && (s[backIndex] < 'a' || s[backIndex] > 'z') && (s[backIndex] < '0' || s[backIndex] > '9') && (s[backIndex] < 'A' || s[backIndex] > 'Z')){
                backIndex--;
            }
            
            if (s[index] >= 'A' && s[index] <= 'Z'){
                s[index] = s[index] + ('a' - 'A');
            }
            if (s[backIndex] >= 'A' && s[backIndex] <= 'Z'){
                s[backIndex] = s[backIndex] + ('a' - 'A');
            }
            
            if (s[index] != s[backIndex]){
                isPalindrome = false;
            }
        }
        return isPalindrome;
    }
};
// TS:O(n) SC:O(1)
// slower. First you remove and process the full string and then you check it.
class Solution {
public:
    bool isPalindrome(string s) {
        for (int index = 0; index < s.size(); index++){
            if (s[index] >= 'A' && s[index] <= 'Z'){
                s[index] = s[index] + ('a' - 'A');
            }
            else if ((s[index] < 'a' || s[index] > 'z') && (s[index] < '0' || s[index] > '9')){
                s.erase(s.begin()+index);
                index--;
            }
        }
        bool isPalindrome = true;
        for (int index = 0; index < s.size() / 2 && isPalindrome; index++){
            if (s[index] != s[s.size() - index - 1]){
                isPalindrome = false;
            }
        }
        return isPalindrome;
    }
};