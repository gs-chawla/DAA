#include <bits/stdc++.h>
using namespace std;

int delrow[] = {-1, 0, +1, 0};
int delcol[] = {0, +1, 0, -1};
class Solution
{

public:
    int numberOfEclaves(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));
        vector<vector<int>> dist(n, vector<int>(m, 0));

        queue<pair<int, int>> q;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {

                if (i == 0 || j == 0 || i == n - 1 || j == m - 1)
                {
                    if (grid[i][j] == 1)
                    {
                        q.push({i, j});
                        vis[i][j] = 1;
                    }
                }
            }
        }

        while (!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++)
            {
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];

                if (nrow >= 0 and nrow < n and ncol >= 0 and ncol < n and vis[nrow][ncol] == 0 and grid[nrow][ncol] == 1)
                {
                    q.push({nrow, ncol});
                }
            }
        }

        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1 and vis[i][j] == 0)
                    cnt++;
            }
        }
        return cnt;
    }
};
