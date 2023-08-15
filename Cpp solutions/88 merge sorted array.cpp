// https://leetcode.com/problems/merge-sorted-array
// TS:O(n) SC:O(1)
// insert from second vector into first vector and separatly increment indexes.
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> result;
        int index2 = 0;
        for (int index = 0; index < m + n; index++){
            if (index-index2 >= m || (index2 < nums2.size() && nums1[index] >= nums2[index2])){
                nums1.insert(nums1.begin()+index, nums2[index2]);
                index2++;
            }
        }
        nums1.erase(nums1.begin() + m + n, nums1.end());
    }
};