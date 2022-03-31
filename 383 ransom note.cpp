// https://leetcode.com/problems/ransom-note
// TC: O(n) SC: O(1)
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        bool isConstructable = true;
        vector<int> letters(26,0);
        for (int index = 0; index < magazine.size(); index++){
            letters[magazine[index]-'a']++;
        }
        int index = 0;
        while (isConstructable == true && index < ransomNote.size()){
            if (letters[ransomNote[index]-'a'] > 0){
                letters[ransomNote[index]-'a']--;
            }
            else {
                isConstructable = false;
            }
            index++;
        }
        return isConstructable;
    }
};