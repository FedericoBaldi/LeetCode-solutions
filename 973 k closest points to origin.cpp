// https://leetcode.com/problems/k-closest-points-to-origin
// TS:O(nlogn) SC:O(n)
// calculate distances and sort them. pick them in order up to k.
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<pair<int,int>> distances(points.size());
        for (int index = 0; index < points.size(); index++){ // calculate distances
            distances[index].first = points[index][0] * points[index][0] + points[index][1] * points[index][1];
            distances[index].second = index;
        }
        sort(distances.begin(), distances.end());
        /*cout << distances[0];
        cout << points[distances[0]][0] << " " << points[distances[0]][1];*/
        vector<vector<int>> kPoints;
        for(int index = 0; index < k; index++){
            kPoints.push_back(points[distances[index].second]);
        }
        return kPoints;
    }
};