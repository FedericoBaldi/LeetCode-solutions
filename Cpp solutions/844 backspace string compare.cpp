// https://leetcode.com/problems/backspace-string-compare
// TS:O(n) SC:O(1)
// make the strings comparable. use stack to keep track of #
// or you could save in stack the chars and remove them when you find #
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        s = clearString(s);
        t = clearString(t);
        return s==t;
    }
private:
    string clearString(string cString){
        stack<int> backspaceStack;
        for (int index = cString.size() - 1; index >= 0; index--){
            if (cString[index] == '#'){
                backspaceStack.push(1);
                cString.erase(cString.begin()+index);
            }
            else if (!backspaceStack.empty()){
                cString.erase(cString.begin()+index);
                backspaceStack.pop();
            }
        }
        return cString;
    }
};