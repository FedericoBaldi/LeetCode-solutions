// https://leetcode.com/problems/remove-palindromic-subsequences
// TS:O(n) SC:O(1)
// since we have only 2 possible characters in the string and we can remove subsequences, the answer can only be 1 or 2.
// 1 if the string is already palyndrom, or else 2. It cannot be 0 because the problem state we have at least s.size() > 0
class Solution {
public:
    int removePalindromeSub(string s) {
        for (int index = 0, indexBack = s.size()-1; index < s.size()/2 && indexBack >= s.size()/2; index++, indexBack--){
            if (s[index] != s[indexBack]){
                return 2;
            }
        }
        return 1;
    }
};