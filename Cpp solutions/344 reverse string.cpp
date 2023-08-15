// https://leetcode.com/problems/reverse-string
// TC: O(n) SC: O(1)
class Solution {
public:
    void reverseString(vector<char>& s) {
        string reverse;
        for(int index = 0; index < s.size()/2; index++){
            char app = s[index];
            s[index]  = s[s.size() - index - 1];
            s[s.size() - index - 1] = app;
        }
    }
};