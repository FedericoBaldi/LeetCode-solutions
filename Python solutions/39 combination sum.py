# https://leetcode.com/problems/combination-sum
# TC: o(2^target * target) SC: o(k * target) k = number of sums
# Select one path and go down, then select another.
class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
    res = []
    comb = []
    def helper(target_sum: int, index: int):
        if target_sum <= 0 or index >= len(candidates):
            if target_sum == 0:
                res.append(comb[:])
            return
        comb.append(candidates[index])
        helper(target_sum - candidates[index], index)
        comb.pop()
        helper(target_sum, index + 1)
    helper(target, 0)
    return res
        
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        comb = []
        candidates.sort()
        def app (curr_index: int, curr_target: int, curr_comb: List[int]):
            res = curr_target - candidates[curr_index]
            if res >= 0:
                curr_comb.append(candidates[curr_index])
                if res == 0:
                    comb.append(curr_comb.copy())
                else:
                    for index in range(curr_index, len(candidates)):
                        app(index, res, curr_comb)
                curr_comb.pop()
        
        for index in range(len(candidates)):
            app(0, target, [])
        return comb
