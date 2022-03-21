// https://leetcode.com/problems/climbing-stairs
// recursive TLE TS: O(n^2) SC: O(1) 
class Solution {
public:
    int climbStairs(int n) {
        int waysToClimb = 0;
        if (n > 0){
            waysToClimb += climbStairs(n-2);
            waysToClimb += climbStairs(n-1);
        }
        else if (n == 0){
            waysToClimb++;
        }
        return waysToClimb;
    }
};
// iterative TS: O(n) SC: O(1)
class Solution {
public:
    int climbStairs(int n) {
        int waysToClimb = n;
        int prev = 2;
        int prev2 = 1;
        for (int index = 2; index < n; index++){
            waysToClimb = prev + prev2;
            prev2 = prev;
            prev = waysToClimb;
        }
        return waysToClimb;
    }
};