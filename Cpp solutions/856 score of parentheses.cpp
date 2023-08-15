// https://leetcode.com/problems/score-of-parentheses
// TC: O(n) SC: O(n)
class Solution {
public:
    int scoreOfParentheses(string s) {
        int score = 0;
        stack<int> scoreStack;
        for (int index = 0; index < s.size(); index++){
            if (s[index] == '('){
                scoreStack.push(score);
                score = 0;
            }
            else {
                score = scoreStack.top() + max(score * 2, 1);
                scoreStack.pop();
            }
        }
        return score;
    }
};
// TC: O(n) SC: O(1)
class Solution {
public:
    int scoreOfParentheses(string s) {
        int res = 0;
        int score = 1;
        int counted = 0;
        for(int index = 0; index < s.size(); index++){
            if(s[index]=='('){
                score*=2;
                counted=0;
            }else{
                score/=2;
                if(counted == 0){
                    res+=score;
                    counted = 1;
                }
            }
        }
        return res;
    }
};