# https://leetcode.com/problems/two-sum
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> indexes;
        map<int,int> numbersMap;
        int pairIndex = 0;
        int index = 0;
        while (pairIndex == 0 && index < nums.size()) {
            pairIndex = numbersMap[target - nums[index]];
            if (pairIndex == 0){
                numbersMap[nums[index]] = index + 1;
            }
            else{
                indexes.push_back(pairIndex-1);
                indexes.push_back(index);
            }
            index++;
        }
        return indexes;
    }
};