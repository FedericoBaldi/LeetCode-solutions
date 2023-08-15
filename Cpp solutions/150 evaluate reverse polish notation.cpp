// https://leetcode.com/problems/evaluate-reverse-polish-notation
// TS:O(n) SC:O(n)
// use stack to store and retrive in the right order the numbers
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stackRes;
        for (int index = 0; index < tokens.size(); index++){
            if (tokens[index] == "*" || tokens[index] == "/" || tokens[index] == "+" || tokens[index] == "-"){
                int second = stackRes.top();
                stackRes.pop();
                int first = stackRes.top();
                stackRes.pop();
                if (tokens[index] == "*"){
                    stackRes.push(first * second);
                }
                else if (tokens[index] == "/"){
                    stackRes.push(first / second);
                }
                else if (tokens[index] == "+"){
                    stackRes.push(first + second);
                }
                else if (tokens[index] == "-"){
                    stackRes.push(first - second);
                }
            }
            else{
                stackRes.push(stoi(tokens[index]));
            }
        }
        return stackRes.top();
    }
};