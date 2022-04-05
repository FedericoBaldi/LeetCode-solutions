// https://leetcode.com/problems/check-if-all-as-appears-before-all-bs
// TS:O(n) SC:O(1)
class Solution {
public:
    bool checkString(string s) {
        bool isCorrect = true;
        int index = 0;
        bool isSwitch = false;
        while (isCorrect && index < s.size()){
            if (isSwitch && s[index] != 'b'){
                isCorrect = false;
            }
            else if (s[index] == 'b'){
                isSwitch = true;
            }
            index++;
        }
        return isCorrect;
    }
};