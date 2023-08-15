# https://leetcode.com/problems/excel-sheet-column-number
class Solution {
public:
    int titleToNumber(string columnTitle) {
        int titleNumber = 0;
        for(int index = 0; index < columnTitle.size(); index++){
            int rebasedLetter = (int)columnTitle[index] - (int)'A' + 1;
            if (index != columnTitle.size() - 1){
                titleNumber += rebasedLetter * pow(26,columnTitle.size()-index-1);
            }
            else{
                titleNumber += rebasedLetter; //rebase from "A" 
            }
        }
        return titleNumber;
    }
};