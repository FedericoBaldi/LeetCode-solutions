// https://leetcode.com/problems/implement-queue-using-stacks
// TS:O(n) SC:O(n)
class MyQueue {
private:
    stack<int> firstStack;
    stack<int> secondStack;
    
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        firstStack.push(x);
    }
    
    int pop() {
        int topS = peek();
        secondStack.pop();
        return topS;
    }
    
    int peek() {
        if (secondStack.empty()){
            while (!firstStack.empty()){
                int topS = firstStack.top();
                firstStack.pop();
                secondStack.push(topS);
            }
        }
        return secondStack.top();
    }
    
    bool empty() {
        return (firstStack.empty() && secondStack.empty());
    }
};