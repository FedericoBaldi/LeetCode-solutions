# https://leetcode.com/problems/combination-sum
class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
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