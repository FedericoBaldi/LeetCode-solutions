// https://leetcode.com/problems/game-of-life
// TS:O(mn) SC:O(1)
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        for(int row = 0; row < board.size(); row++){
            for(int col = 0; col < board[0].size(); col++){
                int alive = check(board, row-1, col);
                alive += check(board, row-1, col-1);
                alive += check(board, row-1, col+1);
                alive += check(board, row, col-1);
                alive += check(board, row, col+1);
                alive += check(board, row+1, col);
                alive += check(board, row+1, col-1);
                alive += check(board, row+1, col+1);
                if (board[row][col] == 0){
                    if (alive == 3){
                        board[row][col] = 2;
                    }
                }
                else{
                    if (alive < 2 || alive > 3){
                        board[row][col] = 3;
                    }
                }
            }
        }
        for(int row = 0; row < board.size(); row++){
            for(int col = 0; col < board[0].size(); col++){
                if (board[row][col] == 2){
                    board[row][col] = 1;
                }
                else if (board[row][col] == 3){
                    board[row][col] = 0;
                }
            }
        }
    }
private:
    int check(vector<vector<int>>& board, int row, int col){
        if (row >= 0 && col >= 0 && row < board.size() && col < board[0].size() && 
            (board[row][col] == 1 || board[row][col] == 3)){
            return 1;
        }
        return 0;
    }
};