// https://leetcode.com/problems/majority-element
// TC:O(n) SC:O(n)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> elements;
        for (int index = 0; index < nums.size(); index++){
            elements[nums[index]]++;
            if (elements[nums[index]] > nums.size() / 2){
                return nums[index];
            }
        }
        return -1;
    }
};