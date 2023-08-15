// https://leetcode.com/problems/rotting-oranges
// TS:O(n*m) SC:O(n*m)
// implement a queue to evaluate neighbours of rotten oranges.(BFS)
// the trick is to go through the initial size of the queue at every iteration and then repeat with newly rot oranges.
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        queue<pair<int, int>> oranges;
        int fresh = 0;
        for (int index = 0; index < grid.size(); index++){
            for (int indexJ = 0; indexJ < grid[0].size(); indexJ++){
                if (grid[index][indexJ] == 2){
                    oranges.push({index, indexJ});
                }
                else if (grid[index][indexJ] == 1){
                    fresh++;
                }
            }
        }
        if (fresh == 0){
            return 0;
        }
        int minutes = 0;
        while (!oranges.empty()){
            int sizeQ = oranges.size();
            for (int index = 0; index < sizeQ; index++){
                pair<int, int> eval = oranges.front();
                oranges.pop();
                for (int indexD = 0; indexD < directions.size(); indexD++){
                    int checkX = eval.first + directions[indexD][0];
                    int checkY = eval.second + directions[indexD][1];
                    if (checkX >= 0 && checkX < grid.size() && checkY >= 0 && checkY < grid[0].size() && grid[checkX][checkY] == 1){
                        grid[checkX][checkY] = 2;
                        oranges.push({checkX, checkY});
                        fresh--;
                    }
                }
            }
            
            minutes++;
        }
        if (fresh != 0){
            return -1;
        }
        return minutes-1;
    }
};