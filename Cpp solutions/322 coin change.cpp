// https://leetcode.com/problems/coin-change
// TS:O(n*m) SC:O(n*m)
// top-down memoization DP
class Solution {
    vector<vector<int>> coinsCalc;
private:
    int changes(vector<int>& coins, int amount, int index){
        if (amount == 0){
            return 0;
        }
        
        if (index >= coins.size() || amount < 0){
            return INT32_MAX - 1;
        }
        
        if (coinsCalc[index][amount] != -1){
            return coinsCalc[index][amount];
        }
        
        int coinsNumber = INT32_MAX - 1;
        if (amount >= coins[index]){
            coinsNumber = changes(coins, amount - coins[index], index) + 1;
        }
        coinsNumber = min(changes(coins, amount, index+1), coinsNumber);
        coinsCalc[index][amount] = coinsNumber;
        return coinsNumber;
    }
    
public:
    int coinChange(vector<int>& coins, int amount) {
        coinsCalc = vector<vector<int>>(12, vector<int> (1e4 + 1, -1));
        int minCoins = changes(coins, amount, 0);
        if (minCoins == INT32_MAX - 1){
            minCoins = -1;
        }
        return minCoins;
    }
};
// TLE TS:O(2^n) SC:O(n)
class Solution {
private:
    int changes(vector<int>& coins, int amount, int index){
        if (amount == 0){
            return 0;
        }
        
        if (index >= coins.size() || amount < 0){
            return INT32_MAX - 1;
        }
        
        int coinsNumber = INT32_MAX - 1;
        if (amount >= coins[index]){
            coinsNumber = changes(coins, amount - coins[index], index) + 1;
        }
        coinsNumber = min(changes(coins, amount, index+1), coinsNumber);
        return coinsNumber;
    }
    
public:
    int coinChange(vector<int>& coins, int amount) {
        int minCoins = changes(coins, amount, 0);
        if (minCoins == INT32_MAX - 1){
            minCoins = -1;
        }
        return minCoins;
    }
};