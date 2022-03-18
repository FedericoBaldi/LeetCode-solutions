// https://leetcode.com/problems/find-smallest-letter-greater-than-target
// TC: O(logn) SC: O(1)
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int left = 0;
        int right = letters.size() - 1;
        if (target >= letters[right]){
			return letters[0];
		}
        while (left < right){
            int mid = left + (right - left) / 2;
            if (letters[mid] <= target){
                left = mid + 1;
            }
            else {
                right = mid;
            }
        }
        return letters[left];
    }
};
// TC: O(n) SC: O(1)
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        char maxChar = letters[0];
		if ((int)target > letters[letters.size()-1){
			return maxChar;
		}
        int index = 0;
        bool isFound = false;
        while (isFound == false && index < letters.size()){
            if (letters[index] > target){
                isFound = true;
                maxChar = letters[index];
            }
            index++;
        }
        return maxChar;
    }
};