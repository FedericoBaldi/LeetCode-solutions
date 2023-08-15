// https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii
// TS:O(n) SC:O(1)
class Solution {
public:
    string removeDuplicates(string s, int k) {
        string result;
        stack<pair<char, int>> stackS;
        for(int index = 0; index < s.size(); index++){
            if (!stackS.empty() && stackS.top().first == s[index]){
                stackS.top().second++;
            }
            else {
                stackS.push({s[index], 1});
            }
            if (stackS.top().second == k){
                stackS.pop();
            }
        }
        while (!stackS.empty()){
            for (int index = 0; index < stackS.top().second; index++){
                result += stackS.top().first;
            }
            stackS.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
// TLE TS:O(n^2) SC:O(1)
class Solution {
public:
    string removeDuplicates(string s, int k) {
        bool hasDuplicates = true;
        while (hasDuplicates){
            hasDuplicates = false;
            int index = 0;
            while (index + k <= s.size()){
                int check = index;
                bool isDuplicate = true;
                while (isDuplicate && check < k + index -1){
                    if (s[check] != s[check + 1]){
                        isDuplicate = false;
                    }
                    check++;
                }
                if (isDuplicate){
                    hasDuplicates = true;
                    s.erase(index, k);
                }
                else{
                    index++;
                }
            }
        }
        return s;
    }
};