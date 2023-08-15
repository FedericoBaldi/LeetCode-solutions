// https://leetcode.com/problems/find-nearest-point-that-has-the-same-x-or-y-coordinate
// TLE TS:O(n) SC:O(1)
class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int indexMin = -1;
        int distanceMin = INT_MAX;
        for (int index = 0; index < points.size(); index++){
            if (x == points[index][0] || y == points[index][1]){
                int pointDistance = abs(x - points[index][0]) + abs(y - points[index][1]);
                if (pointDistance < distanceMin){
                    distanceMin = pointDistance;
                    indexMin = index;
                }
            }
        }
        return indexMin;
    }
};
