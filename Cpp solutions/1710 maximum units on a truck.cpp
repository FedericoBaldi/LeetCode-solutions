// https://leetcode.com/problems/maximum-units-on-a-truck
// TS:O(n) SC:O(1)
// since we the boxes can be used partially, we can sort the box types by the number of units per box 
// and get as much as possible boxes inside the truck
class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), [](auto &a, auto &b){return a[1] > b[1];});
        int maxUnits = 0;
        for (int index = 0; index < boxTypes.size() && truckSize > 0; index++){
            maxUnits += min(truckSize, boxTypes[index][0]) * boxTypes[index][1];
            truckSize -= boxTypes[index][0];
        }
        return maxUnits;
    }
};