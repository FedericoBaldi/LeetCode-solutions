// https://leetcode.com/problems/largest-values-from-labels
// TS:O(nlogn) SC:O(n)
// greedy approach, from the biggest to the smalles and check the conditions(with a map)
// make a vector of pair to solve the problem of parallel sorting. you could use a multimap as well.
class Solution {
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int numWanted, int useLimit) {   
        unordered_map<int, int> usedMap;
        vector<pair<int, int>> pairArrays;
        int sum = 0;
        int usedNumbers = 0;
        for (int index = 0; index < values.size(); index++){
            pairArrays.emplace_back(values[index], labels[index]);
        }
        sort(pairArrays.begin(), pairArrays.end());
        for (int index = pairArrays.size()-1; index >= 0 && usedNumbers < numWanted; index--){
            if (usedMap[pairArrays[index].second] < useLimit){
                usedMap[pairArrays[index].second]++;
                sum += pairArrays[index].first;
                usedNumbers++;
            }
        }
        return sum;
    }
};