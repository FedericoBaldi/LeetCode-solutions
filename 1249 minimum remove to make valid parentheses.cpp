// https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses
// TS: O(n) SC: O(n) 
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string validString = "";
        stack<int> parenthesesStack;
        vector<bool> toKeep(s.size(), false);
        for (int index = 0; index < s.size(); index++){
            if (s[index] == '('){
                parenthesesStack.push(index);
            }
            else if(s[index] == ')'){
                if (parenthesesStack.empty() == false){
                    toKeep[index] = true;
                    toKeep[parenthesesStack.top()] = true;
                    parenthesesStack.pop();
                }
            }
            else{
                toKeep[index] = true;
            }
        }
        for (int index = 0; index < s.size(); index++){
            if (toKeep[index] == true){
                validString += s[index];
            }
        }
        return validString;
    }
};