// https://leetcode.com/problems/validate-binary-search-tree
// TS:O(n*m) SC:O(1)
// check the matrix and use x to mark connected pieces of land. (BFS)
class Solution {
private:
    vector<vector<int>> directions ={{-1, 0}, {1, 0}, {0, -1}, {0, 1},};
    void propagate(int indexX, int indexY, vector<vector<char>>& grid){
        for (int indexD = 0; indexD < directions.size(); indexD++){
            int xCheck = indexX + directions[indexD][0];
            int yCheck = indexY + directions[indexD][1];
            if (xCheck >= 0 && xCheck < grid.size() && yCheck >= 0 && yCheck < grid[0].size()){
                if (grid[xCheck][yCheck] == '1'){
                    grid[xCheck][yCheck] = 'x';
                    propagate(xCheck, yCheck, grid);
                }
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int nIslands = 0;
        for(int index = 0; index < grid.size(); index++){
            for(int indexJ = 0; indexJ < grid[0].size(); indexJ++){
                if (grid[index][indexJ] == '1'){
                    grid[index][indexJ] = 'x';
                    propagate(index, indexJ, grid);
                    nIslands++;
                }
            }
        }
        return nIslands;
    }
};