// https://leetcode.com/problems/merge-intervals
// TS:O(nlogn) SC:O(n)
// sort before merging. merge one by one.
class Solution {
private:
    static bool sortByStart(const vector<int> &first, const vector<int> &second){
        return first[0] < second[0]; 
    }
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> mergedInt;
        sort(intervals.begin(), intervals.end(), sortByStart);
        mergedInt.push_back(intervals[0]);
        for (int index = 1; index < intervals.size(); index++){
            if (mergedInt[mergedInt.size()-1][1] >= intervals[index][0]){
                mergedInt[mergedInt.size()-1][0] = min(mergedInt[mergedInt.size()-1][0], intervals[index][0]);
                mergedInt[mergedInt.size()-1][1] = max(mergedInt[mergedInt.size()-1][1], intervals[index][1]);
            }
            else{
                mergedInt.push_back(intervals[index]);
            }
        }
        return mergedInt;
    }
};