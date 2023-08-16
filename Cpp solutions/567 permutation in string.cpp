// https://leetcode.com/problems/permutation-in-string
// TC: O(n) SC: O(1)
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s2.size() < s1.size()){
            return false;
        }
        vector<int> frequencies(26, 0);
        for (int index = 0; index < s1.size(); index++){
            frequencies[s1[index] - 'a']++;
        }

        int start = 0;
        int stop;
        for (stop = 0; stop < s2.size(); stop++){
            frequencies[s2[stop] - 'a']--;
            bool check = true;
            for (int index = 0; index < frequencies.size(); index++){
                if (frequencies[index] != 0){
                    check = false;
                    break;
                }
            }
            if (check){
                return true;
            }
            if (stop - start + 1 == s1.size()){
                frequencies[s2[start] - 'a']++;
                start++;
            }
        }
        return false;
    }
};

class Solution2 {
public:
    bool checkInclusion(string s1, string s2) {
        int indexLeft = 0;
        int indexRight = 0;
        for (int index = 0; index < s1.size(); ++index){
            counter[s1[index]]++;
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