// https://leetcode.com/problems/roman-to-integer
// TC: O(n) SC: O(1)
class Solution {
public:
    int romanToInt(string s) {
        int number = 0;
        unordered_map<char, int> romanMap = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        int prevN = 0;
        for (int index = 0; index < s.size(); index++){
            int n = romanMap[s[index]];
            if (n > prevN){
                number += n - prevN - prevN;
            }
            else{
                number += n;
            }
            prevN = n;
        }
        return number;
    }
};