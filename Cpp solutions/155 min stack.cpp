// https://leetcode.com/problems/min-stack
// TS:O(1) SC:O(n)
class MinStack {
private:
    vector<int> stackV;
    vector<int> stackMin;
    
public:
    MinStack() {
        
    }
    
    void push(int val) {
        stackV.push_back(val);
        if (stackMin.empty() || stackMin.back() >= val){
            stackMin.push_back(val);
        }
    }
    
    void pop() {
        if (stackV.back() == stackMin.back()) {
            stackMin.pop_back();
        }
        stackV.pop_back();
    }
    
    int top() {
        return stackV.back();
    }
    
    int getMin() {
        return stackMin.back();
    }

};