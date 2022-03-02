// https://leetcode.com/problems/is-subsequence
class Solution {
public:
    bool isSubsequence(string s, string t) {
        bool isSubsequence = false;
        int index = 0;
        int subIndex = 0;
        while (subIndex < s.size() && index < t.size()){
            if (t[index] == s[subIndex]){
                subIndex++;
            }
            index++;
        }
        if (subIndex == s.size()){
            isSubsequence = true;
        }
        return isSubsequence;
    }
};