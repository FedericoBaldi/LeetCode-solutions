// https://leetcode.com/problems/3sum
// TLE TS:O(n^n) SC:O(1)
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> triplets;
        sort(nums.begin(), nums.end());
        for (int index = 0; index < nums.size(); index++){
            int front = index + 1;
            int back = nums.size() - 1;
            int target = -nums[index];
            while (front < back){
                int sum = nums[front] + nums[back];
                if (target > sum){ // sum - target = 0
                    front++;
                }
                else if (target < sum){
                    back--;
                }
                else {
                    vector<int> newTripl = {nums[index], nums[front], nums[back]};
                    triplets.push_back(newTripl);
                    while (front < back && nums[front] == newTripl[1]){
                        front++;
                    }
                    while (front < back && nums[back] == newTripl[2]){
                        back--;
                    }
                }
            }
            while (index + 1 < nums.size() && nums[index + 1] == nums[index]){
                index++;
            }
        }
        return triplets;
    }
};

