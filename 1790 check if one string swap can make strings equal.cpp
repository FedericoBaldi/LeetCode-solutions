// https://leetcode.com/problems/check-if-one-string-swap-can-make-strings-equal
// TS:O(n) SC:O(1)
class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int badCount = 0;
        if (s1.size() != s2.size()){
            return false;
        }
        char firstBadS1, firstBadS2;
        for (int index = 0; index < s1.size(); index++){
            if (s1[index] != s2[index]){
                badCount++;
                if (badCount == 1){
                    firstBadS1 = s1[index];
                    firstBadS2 = s2[index];
                }
                else if (badCount == 2 && (firstBadS1 != s2[index] || firstBadS2 != s1[index])){
                    badCount++;
                }
            }
        }
        if (badCount == 2 || badCount == 0){
            return true;
        }
        else{
            return false;
        }
    }
};