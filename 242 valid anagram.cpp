// https://leetcode.com/problems/valid-anagram
// TS:O(nlogn) SC:O(1)
// increment and decrement map and then check if not all 0
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()){
            return false;
        }
        unordered_map <char, int> anagramMap;
        for (int index = 0; index < s.size(); index++){
            anagramMap[s[index]]++;
            anagramMap[t[index]]--;
        }
        for (auto mapIterator = anagramMap.begin(); mapIterator != anagramMap.end(); mapIterator++){
            if (mapIterator->second != 0){
                return false;
            }
        }
        return true;
    }
};
// TS:O(n^n) SC:O(1)
// Brute force, find in other string
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()){
            return false;
        }
        for(int index = 0; index < s.size(); index++){
            int found = t.find(s[index]);
            if (found != -1){
                t[found] = '0';
            }
            else{
                return false;
            }
        }
        return true;
    }
};