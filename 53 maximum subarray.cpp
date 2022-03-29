// hhttps://leetcode.com/problems/maximum-subarray
// brute brute force TLE TC: O(n^3) SC: O(1)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = nums[0];
        for (int index = 0; index < nums.size(); index++){
            for (int indexJ = index; indexJ < nums.size(); indexJ++){
                int sum = 0;
                for (int indexK = index; indexK <= indexJ; indexK++){
                    sum += nums[indexK];
                }
                if (maxSum < sum){
                    maxSum = sum;
                }
            }
        }
        return maxSum;
    }
};
// brute force TLE TC: O(n^2) SC: O(1)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = nums[0];
        for (int index = 0; index < nums.size(); index++){
            int sum = 0;
            for (int indexJ = index; indexJ < nums.size(); indexJ++){
                sum += nums[indexJ];
                if (maxSum < sum){
                    maxSum = sum;
                }
            }
        }
        return maxSum;
    }
};
// Kadane's algorithm TC: O(n) SC: O(1)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = nums[0];
		int sum = 0;
        for (int index = 0; index < nums.size(); index++){
            sum += nums[index];
			if (sum < nums[index]{
				sum = nums[index];
			}
			if (maxSum < sum){
				maxSum = sum;
			}
        }
        return maxSum;
    }
};