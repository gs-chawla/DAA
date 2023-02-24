#include <bits/stdc++.h>

using namespace std;
class Solution
{
private:
    void dfs(int node, vector<int> adj[], int vis[], vector<int> &ls)
    {

        vis[n] = {0};
        ls.push_back(node);

        for (auto it : adj[node])
        {

            if (!vis[it])
            {
                dfs(it, adj, vis, ls);
            }
        }
    }

public:
    vector<int> dfsOfGraph(int V, vector<int> adj[])
    {
        int vis[V] = {0};
        int start = 0;
        vector<int> ls;
        dfs(start, adj, vis, ls);
        return ls;
    }
}