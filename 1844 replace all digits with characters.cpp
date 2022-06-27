// https://leetcode.com/problems/replace-all-digits-with-characters
// TS:O(n) SC:O(1)
class Solution {
public:
    string replaceDigits(string s) {
        for (int index = 0; index < s.size(); index+=2){
            s[index+1] = s[index] + s[index+1] - '0';
        }
        return s;
    }
};