// https://leetcode.com/problems/candy
// TS:O(n) SC:O(n)
// pass two times the array. first check the left neighbor and then the right neighbor.
class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> candies(ratings.size(), 1);
        for (int index = 1; index < ratings.size(); index++){
            if (ratings[index] > ratings[index-1]){
                candies[index] = candies[index-1] + 1;
            }
        }
        
        int minCandies = candies[candies.size()-1];
        for (int indexJ = ratings.size()-2; indexJ >= 0; indexJ--){
            if (ratings[indexJ] > ratings[indexJ+1]){
                candies[indexJ] = max(candies[indexJ], candies[indexJ+1]+1);
            }
            minCandies += candies[indexJ];
        }
        return minCandies;
    }
};
// TLE TS:O(n^2) SC:O(n)
// go through the array one time and update the candy array. In the case of rating higher than next rating, you need to back update the previous candies.
class Solution {
public:
    int candy(vector<int>& ratings) {
        int minCandies = 0;
        vector<int> candies(ratings.size(), 1);
        int previousCandies = 0;
        int previousValue = 0;
        for (int index = 0; index < ratings.size(); index++){
            if (previousValue < ratings[index]){
                candies[index] += previousCandies;
            }
            if (index + 1 < ratings.size() && ratings[index] > ratings[index+1]){
                if (candies[index] <= candies[index+1]){
                    candies[index]++;
                }
                for (int indexJ = index; indexJ >= 0; indexJ--){
                    if (indexJ - 1 >= 0 && ratings[indexJ] < ratings[indexJ-1]){
                        candies[indexJ-1] = max(candies[indexJ-1], candies[indexJ]+1);
                    }
                    else{
                        break;
                    }
                }
            }
            previousCandies = candies[index];
            previousValue = ratings[index];
        }
        for (int index = 0; index < candies.size(); index++){
            minCandies += candies[index];
        }
        return minCandies;
    }
};