#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    bool dfs(int node, int parent, int vis[], vector<int> adj[])
    {
        vis[node] = 1;
        for (auto adjNode : adj[node])
        {
            if (!vis[adjNode])
            {
                if (dfs(adjNode, node, vis, adj) == true)
                    return true;
            }
            else if (adjNode != parent)
            {
                return true;
            }
        }
        return false;
    }

public:
    bool isCycle(int V, vector<int> adj[])
    {
        int vis[] = {0};
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                if (dfs(i, -1, vis, adj) == true)
                    return true;
            }
        }
        return false;
    }
};
