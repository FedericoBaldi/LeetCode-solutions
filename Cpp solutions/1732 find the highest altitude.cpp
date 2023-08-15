// https://leetcode.com/problems/find-the-highest-altitude
// TC: O(n) SC: O(1)
class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int maxAltitude = 0;
        int currentAltitude = 0;
        for (int index = 0; index < gain.size(); index++){
            currentAltitude += gain[index];
            if (currentAltitude > maxAltitude){
                maxAltitude = currentAltitude;
            }
        }
        return maxAltitude;
    }
};