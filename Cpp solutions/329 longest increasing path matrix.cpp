// https://leetcode.com/problems/longest-increasing-path-in-a-matrix
// TS:O(mnlog(mn)) SC:O(n*m)
// DP saving the previous calculated results, so that we dont need to calculate them again.
class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int maxPath = 0;
        memoizationMap = vector<vector<int>>(matrix.size(), vector<int>(matrix[0].size()));
        
        for (int index = 0; index < matrix.size()*matrix[0].size(); index++){
            maxPath = max(maxPath, nextPath(matrix, index / matrix[0].size(), index % matrix[0].size(), -1));
        }
        return maxPath;
    }
private:
    vector<vector<int>> memoizationMap;
    
    int nextPath(vector<vector<int>>& matrix, int i, int j, int previous){
        int maxPath = 0;
        if (i < matrix.size() && j < matrix[0].size() && matrix[i][j] > previous){
            if (memoizationMap[i][j]){
                maxPath = memoizationMap[i][j];
            }
            else {
                maxPath = max(maxPath, nextPath(matrix, i+1, j, matrix[i][j]));
                maxPath = max(maxPath, nextPath(matrix, i, j+1, matrix[i][j]));
                maxPath = max(maxPath, nextPath(matrix, i-1, j, matrix[i][j]));
                maxPath = max(maxPath, nextPath(matrix, i, j-1, matrix[i][j]));
                maxPath++;
                memoizationMap[i][j] = maxPath;
            }
        }
        return maxPath;
    }
};
// TLE TS:O(mn*4^(mn)) SC:O(n*m)
class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int maxPath = 0;
        for (int index = 0; index < matrix.size()*matrix[0].size(); index++){
            maxPath = max(maxPath, nextPath(matrix, index / matrix[0].size(), index % matrix[0].size(), -1));
        }
        return maxPath;
    }
private:
    int nextPath(vector<vector<int>>& matrix, int i, int j, int previous){
        int maxPath = 0;
        if (i < matrix.size() && j < matrix[0].size()){
            int current = matrix[i][j];
            if (current > previous){
                maxPath = max(maxPath, nextPath(matrix, i+1, j, current));
                maxPath = max(maxPath, nextPath(matrix, i, j+1, current));
                maxPath = max(maxPath, nextPath(matrix, i-1, j, current));
                maxPath = max(maxPath, nextPath(matrix, i, j-1, current));
                maxPath++;
            }
        }
        return maxPath;
    }
};