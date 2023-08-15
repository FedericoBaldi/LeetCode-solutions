// https://leetcode.com/problems/course-schedule
// TS:O(n*n) SC:O(n*n)
// color the graph while checking for cycles.(DFS)
class Solution {
private: 
    bool checkCycle(vector<vector<int>> &dependencies, vector<int> &visited, int curr){
        if (visited[curr] == 1){
            return false;
        }
        
        if (visited[curr] == 0){
            visited[curr] = 1;
            for (int index = 0; index < dependencies[curr].size(); index++){
                if (!checkCycle(dependencies, visited, dependencies[curr][index])){
                    return false;
                }
            }
            visited[curr] = 2;
        }
        return true;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> dependencies(numCourses);
        vector<int> visited(numCourses, 0);
        for (int index = 0; index < prerequisites.size(); index++){
            dependencies[prerequisites[index][0]].push_back(prerequisites[index][1]);
        }
        
        for (int index = 0; index < visited.size(); index++){
            if (!checkCycle(dependencies, visited, index)){
                return false;
            }
        }
        return true;
    }
};