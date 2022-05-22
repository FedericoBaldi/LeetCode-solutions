// https://leetcode.com/problems/flood-fill
// TS:O(mn) SC:O(1)
// recursive method. do as told.
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int startingColor = image[sr][sc];
        image = fill(image, sr, sc, newColor, startingColor);
        return image;
    }
private:
    vector<vector<int>> fill(vector<vector<int>>& image, int sr, int sc, int newColor, int startingColor) {
        if (newColor != startingColor && sr < image.size() && sr >= 0 && sc < image[0].size() && sc >= 0 && image[sr][sc] == startingColor){
            image[sr][sc] = newColor;
            image = fill(image, sr - 1, sc, newColor, startingColor);
            image = fill(image, sr, sc - 1, newColor, startingColor);
            image = fill(image, sr + 1, sc, newColor, startingColor);
            image = fill(image, sr, sc + 1, newColor, startingColor);
        }
        return image;
    }
};