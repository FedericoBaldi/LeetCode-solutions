// https://leetcode.com/problems/h-index
// TS:O(n^2) SC:O(1)
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int h = 0;
        int publications = 0;
        while (h <= citations.size() && publications == h){
            h++;
            publications = 0;
            int index = 0;
            while (index < citations.size() && publications < h){
                if (citations[index] >= h){
                    publications++;
                }
                index++;
            }
        }
        return h - 1;
    }
};