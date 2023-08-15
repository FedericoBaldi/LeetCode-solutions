// https://leetcode.com/problems/valid-parentheses
// TC: O(n) SC: O(1)
class Solution {
public:
    bool isValid(string s) {
        bool isParenthesesValid = true;
        int index = 0;
        stack<char> parentheses;
        while (isParenthesesValid == true && index < s.size()){
            if (s[index] == '(' || s[index] == '[' || s[index] == '{'){
                parentheses.push(s[index]);
            }
            else if (s[index] == ')'){
                if (parentheses.empty() != true && parentheses.top() == '('){
                    parentheses.pop();
                }
                else{
                    isParenthesesValid = false;
                }
            }
            else if (s[index] == ']'){
                if (parentheses.empty() != true && parentheses.top() == '['){
                    parentheses.pop();
                }
                else{
                    isParenthesesValid = false;
                }
            }
            else if (s[index] == '}'){
                if (parentheses.empty() != true && parentheses.top() == '{'){
                    parentheses.pop();
                }
                else{
                    isParenthesesValid = false;
                }
            }
            else{
                isParenthesesValid = false;
            }
            index++;
        }
        if (parentheses.empty() != true){
            isParenthesesValid = false;
        }
        return isParenthesesValid;
    }
};