// https://leetcode.com/problems/find-original-array-from-doubled-array
// TS:O(nlogn) SC:O(n)
class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        if (changed.size() % 2 != 0){
            return {};
        }
        vector<int> original;
        sort(changed.begin(), changed.end());
        unordered_map <int, int> map;
        for (int index = 0; index < changed.size(); index++){
            map[changed[index]]++;
        }
        for (int index = 0; index < changed.size(); index++){
            int indexDouble = map[changed[index]*2];
            if (map[changed[index]] != 0){
                if (map[changed[index] * 2] != 0){
                    map[changed[index]]--;
                    map[changed[index] * 2]--;
                    original.push_back(changed[index]);
                }
                else {
                    return {};
                }
            }
        }
        return original;
    }
};
// TLE TS:O(n^2) SC:O(n)
class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        sort(changed.begin(), changed.end());
        bool found = true;
        for (int index = 0; index < changed.size() && found; index++){
            found = false;
            for (int indexK = index+1; indexK < changed.size() && changed[indexK] <= changed[index]*2; indexK++){
                if (changed[index] == changed[indexK] / 2){
                    found = true;
                    changed.erase(changed.begin() + indexK);
                    break;
                }
            }
        }
        if (found == false){
            return vector<int>();
        }
        return changed;
    }
};