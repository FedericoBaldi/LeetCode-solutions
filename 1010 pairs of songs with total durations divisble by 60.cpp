// https://leetcode.com/problems/pairs-of-songs-with-total-durations-divisible-by-60
// TC: O(n) SC: O(n)
class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        unordered_map<int,int> songMap;
        int pairsCount = 0;
        for (int index = 0; index < time.size(); index++){
            int minutesNeeded = 0;
            if (time[index] % 60 != 0){
                minutesNeeded = 60 - (time[index] % 60);
            }
            pairsCount += songMap[minutesNeeded];
            songMap[time[index] % 60]++;
        }
        return pairsCount;
    }
};