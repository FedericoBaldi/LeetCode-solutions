// https://leetcode.com/problems/insert-interval/
// TLE TS:O(n) SC:O(n)
// push intervals in result when evaluated not to be mergeable or else merge and go on.
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> result;
        for (int index = 0; index < intervals.size(); index++){
            if (newInterval[0] > intervals[index][1]){
                result.push_back(intervals[index]);
            }
            else if (newInterval[1] < intervals[index][0]){
                result.push_back(newInterval);
                result.insert(result.end(), intervals.begin()+index, intervals.end());
                return result;
            }
            else{
                newInterval[0] = min(newInterval[0], intervals[index][0]);
                newInterval[1] = max(newInterval[1], intervals[index][1]);
            }
        }
        result.push_back(newInterval);
        return result;
    }
};

