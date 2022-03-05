// https://leetcode.com/problems/summary-ranges
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int breakIndex = 0;
        vector<string> ranges;
        string range;
        for (int index = 0; index < nums.size(); index++){
            if (index == nums.size()-1 || nums[index]+1 != nums[index+1]){ // range termination
                if (nums[breakIndex] != nums[index]){ 
                    range = to_string(nums[breakIndex]) + "->" +  to_string(nums[index]);
                }
                else{
                    range = to_string(nums[index]);
                }
                breakIndex = index + 1;
                ranges.push_back(range);
            }
        }
        return ranges;
    }
};