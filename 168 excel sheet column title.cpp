// https://leetcode.com/problems/excel-sheet-column-title
// TS:O(log26) SC:O(1)
class Solution {
public:
    string convertToTitle(int columnNumber) {
        string column;
        while (columnNumber > 0){
            columnNumber--;
            column = column + char(columnNumber % 26 + 'A');
            columnNumber = columnNumber / 26;
        }
        reverse(column.begin(), column.end());
        return column;
    }
};