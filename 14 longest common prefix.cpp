// https://leetcode.com/problems/longest-common-prefix
// TS:O(nm) SC:O(1)
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string longestPrefix = strs[0];
        for (int index = 1; index < strs.size(); index++){
            int stringIndex = 0;
            while (stringIndex < longestPrefix.size() && stringIndex < strs[index].size() && strs[index][stringIndex] == longestPrefix[stringIndex]){
                stringIndex++;
            }
            longestPrefix = (strs[index]).substr(0, stringIndex);
        }
        return longestPrefix;
    }
};