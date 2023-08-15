// https://leetcode.com/problems/last-stone-weight
// TS:O(n^2logn) SC:O(1)
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        while (stones.size() > 1){
            sort(stones.begin(), stones.end());
            int smashResult = stones[stones.size() - 1] - stones[stones.size() - 2];
            if (smashResult != 0){
                stones.insert(stones.begin(), smashResult);
            }
            stones.erase(stones.begin() + (stones.size() - 2));
            stones.erase(stones.begin() + (stones.size() - 1));
        }
        if (stones.size() == 0){
            return 0;
        }
        else{
            return stones[0];
        }
    }
};