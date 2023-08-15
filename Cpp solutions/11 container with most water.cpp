// https://leetcode.com/problems/container-with-most-water
// TLE TS:O(n) SC:O(1)
class Solution {
public:
    int maxArea(vector<int>& height) {
        int front = 0;
        int back = height.size() - 1;
        int areaMax = 0;
        while (front < back){
            int minHeight = min(height[front], height[back]);
            areaMax = max(areaMax, minHeight * (back - front)); 
            while (height[front] <= minHeight && front < back){
                front++;
            }
            while (height[back] <= minHeight && front < back){
                back--;
            }
        }
        return areaMax;
    }
};

