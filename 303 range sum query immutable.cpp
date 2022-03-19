// https://leetcode.com/problems/range-sum-query-immutable
// TC: O(1) SC: O(n)
class NumArray {
private:
    vector<int> vectSums;
public:
    NumArray(vector<int>& nums) {
        vectSums.push_back(0);
        for (int index = 0; index < nums.size(); index++){
            vectSums.push_back(vectSums.back() + nums[index]);
        }
    }
    
    int sumRange(int left, int right) {
        int sum = vectSums[right+1] - vectSums[left];
        return sum;
    }
};
// slow TC: O(n) SC: O(1)
class NumArray {
private:
    vector<int> vectNums;
public:
    NumArray(vector<int>& nums) {
        vectNums = nums;
    }
    
    int sumRange(int left, int right) {
        int sum = 0;
        for (int index = left; index <= right; index++){
            sum += vectNums[index];
        }
        return sum;
    }
};