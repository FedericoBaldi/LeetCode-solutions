// https://leetcode.com/problems/01-matrix
// TLE TS:O(n*n) SC:O(n*n)
// BFS on a matrix. mark the cells not reachable and push cells to check in a queue. check the queue until empty with the problem condition.
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<pair<int,int>> queueP;
        for (int index = 0; index < mat.size(); index++){
            for (int indexJ = 0; indexJ < mat[0].size(); indexJ++){
                if (mat[index][indexJ] == 0){
                    queueP.push({index, indexJ});
                }
                else{
                    mat[index][indexJ] = INT_MAX;
                }
            }
        }
        
        vector<pair<int,int>> directions = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };
        while (!queueP.empty()){
            pair<int,int> current = queueP.front();
            queueP.pop();
            for (int index = 0; index < directions.size(); index++){
                int indexNew = current.first + directions[index].first;
                int indexJNew = current.second + directions[index].second;
                if (indexNew >= 0 && indexJNew >= 0 && indexNew < mat.size() && indexJNew < mat[0].size()){
                    if (mat[indexNew][indexJNew] > mat[current.first][current.second] + 1){
                        mat[indexNew][indexJNew] = mat[current.first][current.second] + 1;
                        queueP.push({indexNew, indexJNew});
                    }
                }
            }
        }
        return mat;
    }
};

