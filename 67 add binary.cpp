// https://leetcode.com/problems/add-binary
// TS:O(n) SC:O(1)
class Solution {
public:
    string addBinary(string a, string b) {
        bool carry = false;
        int indexA = a.size()-1;
        int indexB = b.size()-1;
        string result;
        while (indexA >= 0 || indexB >= 0 || carry == true){
            int sum = 0;
            if (indexA >= 0 && a[indexA] == '1'){
                sum++;
            }
            if (indexB >= 0 && b[indexB] == '1'){
                sum++;
            }
            if (carry == true){
                sum++;
                carry = false;
            }
            if (sum > 1){
                carry = true;
            }
            result.insert(result.begin(), char(48 + sum % 2));
            indexA--;
            indexB--;
        }
        return result;
    }
};