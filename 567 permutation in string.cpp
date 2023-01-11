// https://leetcode.com/problems/permutation-in-string
// TC: O(n) SC: O(1)
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int indexLeft = 0;
        int indexRight = 0;
        for (int index = 0; index < s1.size(); ++index){
            counter[s1[index]]++;
            cout << counter[s1[index]] << endl;
        }
        while (indexRight < s2.size()){
            if (indexRight - indexLeft + 1 > s1.size()){
                if (counter.find(s2[indexLeft]) != counter.end()){
                    counter[s2[indexLeft]]++;
                }
                indexLeft++;
            }
            if (counter.find(s2[indexRight]) != counter.end()){
                counter[s2[indexRight]]--;
                if (evaluateCounter()){
                    return true;
                }
            }
            indexRight++;
        }
        return false;
    }
private:
    unordered_map<char,int> counter;
    bool evaluateCounter(){
        for (auto it = counter.begin(); it != counter.end(); ++it){
            if (it->second != 0){
                return false;
            }
        }
        return true;
    }
};