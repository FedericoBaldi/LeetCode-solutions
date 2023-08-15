// https://leetcode.com/problems/simplify-path
// faster versio with stringstream TS: O(n) SC: O(1)
class Solution {
public:
    string simplifyPath(string path) {
        string canonicalPath = "";
        string word;
        stack<string> stringsPath;
        stringstream sStream(path);
        while(getline(sStream, word, '/')){
            if (word != "" && word != "."){
                if (word != ".."){
                    stringsPath.push(word);
                }
                else if (stringsPath.empty() == false){
                    stringsPath.pop();
                }
            }
            word = "";
        }
        while (stringsPath.empty() == false){
            canonicalPath = "/" + stringsPath.top() + canonicalPath;
            stringsPath.pop();
        }
        if (canonicalPath.empty() == true){
            canonicalPath = "/";
        }
        return canonicalPath;
    }
};
// TS: O(n) SC: O(1)
class Solution {
public:
    string simplifyPath(string path) {
        string canonicalPath = "";
        string word = "";
        stack<string> stringsPath;
        for(int index = 0; index < path.size(); index++){
            if(path[index] != '/'){
                word += path[index];
            }
            if (index == path.size()-1 || path[index] == '/'){
                if (word != "" && word != "."){
                    if (word != ".."){
                        stringsPath.push(word);
                    }
                    else if (stringsPath.empty() == false){
                        stringsPath.pop();
                    }
                }
                word = "";
            }
        }
        while (stringsPath.empty() == false){
            canonicalPath = "/" + stringsPath.top() + canonicalPath;
            stringsPath.pop();
        }
        if (canonicalPath.empty() == true){
            canonicalPath = "/";
        }
        return canonicalPath;
    }
};
