// https://leetcode.com/problems/contains-duplicate
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        bool hasDuplicates = false;
        map<int,int> values;
        int index = 0;
        while (hasDuplicates == false && index < nums.size()){
            if(values[nums[index]] == 0){
                values[nums[index]] = 1;
            }
            else{
                hasDuplicates = true;
            }
            index++;
        }
        return hasDuplicates;
    }
};