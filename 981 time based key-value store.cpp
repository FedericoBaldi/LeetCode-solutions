// https://leetcode.com/problems/time-based-key-value-store
// set get TS:O(1) SC:O(n) get TS:O(logn) SC:O(n)
// binary search with upperbound variation.
class TimeMap {
private:
    unordered_map<string, vector<pair<int, string>>> timesMap;
    
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        timesMap[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        int low = 0;
        int high = timesMap[key].size();
        while (low < high){
            int mid = low + (high - low) / 2;
            if (timesMap[key][mid].first <= timestamp){
                low = mid + 1;
            }
            else{
                high = mid;
            }
        }
        if (low > 0 && low <= timesMap[key].size()){
            return timesMap[key][low-1].second;
        }
        return "";
    }
};