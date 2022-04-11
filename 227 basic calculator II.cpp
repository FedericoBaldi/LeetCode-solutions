// https://leetcode.com/problems/basic-calculator-ii
// TS:O(n) SC:O(n)
class Solution {
public:
    int calculate(string s) {
        stack<int> stackNumbers;
        int tmp = 0;
        char operation = '+';
        int index = 0;
        while (index <= s.size()){
            if (index >= s.size() || s[index] != ' '){
                if (index < s.size() && s[index] != '/' && s[index] != '*' && s[index] != '+' && s[index] != '-'){
                    tmp = tmp * 10 + (s[index] - '0');
                }
                else {
                    if (operation == '+'){
                    }
                    else if (operation == '-'){
                        tmp = -tmp;
                    }
                    else if (operation == '/'){
                        tmp = stackNumbers.top() / tmp;
                        stackNumbers.pop();
                    }
                    else if (operation == '*'){
                        tmp = stackNumbers.top() * tmp;
                        stackNumbers.pop();
                    }
                    stackNumbers.push(tmp);
                    tmp = 0;
                    operation = s[index];
                } 
            }
            index++;
        }
        int result = 0;
        while (!stackNumbers.empty()){
            result += stackNumbers.top();
            stackNumbers.pop();
        }
        return result;
    }
};
// TLE TS:O(nlogn) SC:O(1)
class Solution {
public:
    int calculate(string s) {
        bool isPriority = false;
        int startFirstNumber, endFirstNumber;
        int startSecondNumber = s.size(), endSecondNumber = s.size();
        for (int index = 0; index < s.size(); index++){
            while (s[index] == ' '){
                s.erase(index, 1);
            }
			if (s[index] == '/' || s[index] == '*'){ //to make it faster
				isPriority = true;
			}
        }
        int index = 0;
        while (index < s.size()){
            startFirstNumber = min(index, startSecondNumber);
            index = startFirstNumber;
            index++;
            while (s[index] != ' ' && s[index] != '/' && s[index] != '*' && s[index] != '+' && s[index] != '-' && index < s.size()){
                index++;
            }
            endFirstNumber = min(index, endSecondNumber);
            int firstNumber = stoi(s.substr(startFirstNumber, endFirstNumber - startFirstNumber), nullptr);
            if (index < s.size()){
                int operand = index;
                index++;
                startSecondNumber = index;
                while (s[index] != ' ' && s[index] != '/' && s[index] != '*' && s[index] != '+' && s[index] != '-' && index < s.size()){
                    index++;
                }
                endSecondNumber = index;
                int secondNumber = stoi(s.substr(startSecondNumber, endSecondNumber - startSecondNumber), nullptr);
                int result;
                bool isResult = true;
                if (isPriority){
                    switch (s[operand]){
                        case '/': result = firstNumber / secondNumber;
                        break;
                        case '*': result = firstNumber * secondNumber;
                        break;
                        default: isResult = false;
                    }
                }
                else{
                    switch (s[operand]){
                        case '+': result = firstNumber + secondNumber;
                        break;
                        case '-': result = firstNumber - secondNumber;
                        break;
                    }
                }
                if (isResult){
                    if (index < s.size()){
                        index = startFirstNumber;
                    }
                    s.erase(startFirstNumber, endSecondNumber - startFirstNumber);
                    s.insert(startFirstNumber, to_string(result));
                }
                if (index >= s.size()){
                    isPriority = false;
                    index = 0;
                }
            }
        }
        return stoi(s,nullptr);
    }
};