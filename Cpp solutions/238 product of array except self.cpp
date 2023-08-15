// https://leetcode.com/problems/product-of-array-except-self
// TS:O(n) SC:O(1) optimized single loop (without using division)
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> answers(nums.size(), 1);
        int pre = 1;
        int post = 1;
        for (int index = 0; index < nums.size(); index++){
            answers[index] *= post;
            post *= nums[index];
            answers[nums.size() - 1 - index] *= pre;
            pre *= nums[nums.size() - 1 - index];
        }
        return answers;
    }
};
// TS:O(n) SC:O(1) (without using division)
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> answers(nums.size(), 1);
        for (int index = 1; index < nums.size(); index++){ //post
            answers[index] = answers[index - 1] * nums[index - 1];
        }
        int pre = 1;
        for (int index = nums.size() - 1; index >= 0; index--){ //pre
            answers[index] *= pre;
            pre *= nums[index];
        }
        return answers;
    }
};
// TLE TS:O(n^2) SC:O(1)
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> answers;
        for (int index = 0; index < nums.size(); index++){
            int answer = 1;
            for (int indexJ = 0; indexJ < nums.size(); indexJ++){
                if (index != indexJ){
                    answer *= nums[indexJ];
                }
            }
            answers.push_back(answer);
        }
        return answers;
    }
};