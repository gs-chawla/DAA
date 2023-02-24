#include <bits/stdc++.h>

using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};
vector<int> verticalOrder(node *root)
{
    map<int, map<int, vector<int>>> nodes;

    queue<pair<node *, pair<int, int>>> q;

    vector<int> ans;

    if (root == NULL)
        return ans;

    q.push(make_pair(root, make_pair(0, 0)));

    while (!q.empty())
    {
        pair<node *, pair<int, int>> temp = q.front();
        q.pop();
        node *frontNode = temp.first;
        int hd = temp.second.first;   // horizontal distance
        int lvl = temp.second.second; // level

        nodes[hd][lvl].push_back(frontNode->data);

        if (frontNode->left)
            q.push(make_pair(frontNode->left, make_pair(hd - 1, lvl + 1)));

        if (frontNode->right)
        {
            q.push(make_pair(frontNode->right, make_pair(hd + 1, lvl + 1)));
        }
    }
    for (auto i : nodes)
    {
        for (auto j : i.second)
        {
            for (auto k : j.second)
            {
                ans.push_back(k);
            }
        }
    }
    return ans;
}
