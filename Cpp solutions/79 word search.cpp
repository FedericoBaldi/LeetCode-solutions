// https://leetcode.com/problems/word-search
// TS:O(n^2) SC:O(1)
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        bool exists = false;
        int index = 0;
        while (exists == false && index < board.size() * board[0].size()){
            int row = index / board[0].size(); //flatten matrix
            int col = index % board[0].size();
            if (board[row][col] == word[0]){
                if (word.size() == 1){
                    exists = true;
                }
                else{
                    char cur = board[row][col];
                    board[row][col] = '0';
                    exists = existsAround(board, row, col, word, 1);
                    board[row][col] = cur;
                }
            }
            index++;
        }
        return exists;
    }
    bool existsAround(vector<vector<char>>& board, int x, int y, string word, int indexWord){
        bool exists = false;
        for (int index = 0; index < 4; index++){ // look around
            int xNext = x, yNext = y;
            if (index == 0){
                yNext--;
            }
            else if (index == 1){
                xNext++;
            }
            else if (index == 2){
                yNext++;
            }
            else {
                xNext--;
            }
            if (xNext >= 0 && yNext >= 0 && xNext < board.size() && yNext < board[0].size()
                && board[xNext][yNext] == word[indexWord]){
                if (indexWord + 1 < word.size()){
                    char cur = board[xNext][yNext];
                    board[xNext][yNext] = '0';
                    exists |= existsAround(board, xNext, yNext, word, indexWord + 1);
                    board[xNext][yNext] = cur;
                }
                else {
                    exists = true;
                }
            }
        }
        return exists;
    }
};