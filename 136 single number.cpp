// https://leetcode.com/problems/single-number
// TC: O(n) SP: O(1)
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int singleNum = 0;
        for(int index = 0; index < nums.size(); index++){
            singleNum ^= nums[index];
        }
        return singleNum;
    }
};
// TC: O(n) SP: O(N)
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> numbers;
        int singleNum;
        for(int index = 0; index < nums.size(); index++){
            numbers[nums[index]]++;
        }
        unordered_map<int,int>::iterator it = numbers.begin();
        while(it != numbers.end()){
            if (it->second == 1){
                singleNum = it->first;
            }
            it++;  
        }
        return singleNum;
    }
};