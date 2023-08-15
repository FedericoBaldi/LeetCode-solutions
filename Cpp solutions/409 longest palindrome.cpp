// https://leetcode.com/problems/longest-palindrome
// TS:O(n) SC:O(n)
class Solution {
public:
    int longestPalindrome(string s) {
        int maxPalindrome = 0;
        unordered_map<char, int> charsMap;
        for (int index = 0; index < s.size(); index++){
            charsMap[s[index]]++;
        }
        bool hasOdd = false;
        for (auto mapPointer = charsMap.begin(); mapPointer != charsMap.end(); mapPointer++){
            if (mapPointer->second % 2 == 0){
                maxPalindrome += mapPointer->second;
            }
            else {
                hasOdd = true;
                maxPalindrome += mapPointer->second - 1;
            }
        }
        if (hasOdd){
            maxPalindrome ++;
        }
        return maxPalindrome;
    }
};