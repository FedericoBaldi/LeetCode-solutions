// https://leetcode.com/problems/repeated-dna-sequences
// TS:O(n) SC:O(n) n = sum of all linked list sizes
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int> sequencesMap;
        vector<string> recurringSequences;
        for (int index = 0; index <= (int)s.size() - 10; index++){
            string sequence = s.substr(index, 10);
            sequencesMap[sequence]++;
        }
        for (auto iterator = sequencesMap.begin(); iterator != sequencesMap.end(); iterator++){
            if (iterator->second > 1){
                recurringSequences.push_back(iterator->first);
            }
        }
        return recurringSequences;
    }
};