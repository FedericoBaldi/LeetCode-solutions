// https://leetcode.com/problems/string-without-aaa-or-bbb
// TS:O(n) SC:O(1) n = a+b
class Solution {
public:
    string strWithout3a3b(int a, int b) {
        string str;
        int consecutiveA = 0;
        int consecutiveB = 0;
        while (a != 0 || b!= 0){
            if (a < b && consecutiveB < 2 || consecutiveA > 1){
                str += "b";
                consecutiveA = 0;
                consecutiveB++;
                b--;
            }
            else {
                str += "a";
                consecutiveA++;
                consecutiveB = 0;
                a--;
            }
        }
        return str;
    }
};