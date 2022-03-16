// https://leetcode.com/problems/validate-stack-sequences
// TC: O(n) SC: O(n)
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> pushedStack;
        int indexJ = 0;
        for(int index = 0; index < pushed.size(); index++){
            pushedStack.push(pushed[index]);
            while (pushedStack.empty() == false && pushedStack.top() == popped[indexJ]){
                pushedStack.pop();
                indexJ++;
            }
        }
        return pushedStack.empty();
    }
};