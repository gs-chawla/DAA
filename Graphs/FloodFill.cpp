#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    void dfs(int row, int col, vector<vector<int>> &ans, vector<vector<int>> &image, int newColor, int delRow[], int delCol[], int iniColor)
    {

        ans[row][col] = newColor;
        for (int i = 0; i < 4; i++)
        {
            /* code */
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];
            if (nrow >= 0 and nrow < image.size() and ncol >= 0 and ncol < image[0].size() and
                image[nrow][ncol] == iniColor and ans[nrow][ncol] != newColor)
            {
                dfs(nrow, ncol, ans, image, newColor, delRow, delCol, iniColor);
            }
        } 
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
    {

        int iniColor = image[sr][sc];
        vector<vector<int>> ans = image;
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};
        dfs(sr, sc, ans, image, newColor, delRow, delCol, iniColor);
    }
};
