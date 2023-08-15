// https://leetcode.com/problems/pascals-triangle
// TS:O(n^2) SC:O(n^2)
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> triangle;
        for (int index = 0; index < numRows; index++){
            vector<int> row;
            for (int indexJ = 0; indexJ < index + 1; indexJ++){
                if (indexJ == 0 || indexJ == index){
                   row.push_back(1); 
                }
                else{
                   row.push_back(triangle[index-1][indexJ-1] + triangle[index-1][indexJ]);
                }
            }
            triangle.push_back(row);
        }
        return triangle;
    }
};