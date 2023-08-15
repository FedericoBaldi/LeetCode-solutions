// https://leetcode.com/problems/longest-substring-without-repeating-characters
// TS:O(n) SC:O(1)
// sliding window approach. slide the window until you find a already seen char and reset the start of the sliding window.
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int longestSubstring = 0;
        vector<int> dict(256, -1);
        int indexJ = -1;
        for (int index = 0; index < s.size(); index++){
            if (dict[s[index]] > indexJ){
                 indexJ = dict[s[index]];
            }
            dict[s[index]] = index;
            longestSubstring = max(longestSubstring, index - indexJ);
        }
        return longestSubstring;
    }
};
// TS:O(n^2) SC:O(n)
// try every combination using map to keep track of used chars. slow
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int longestSubstring = 0;
        for (int index = 0; index < s.size(); index++){
            unordered_map<char, int> charMap;
            int indexJ = index;
            while (++charMap[s[indexJ]] == 1 && indexJ < s.size()){
                indexJ++;
            }
            longestSubstring = max(longestSubstring, indexJ - index);
        }
        return longestSubstring;
    }
};