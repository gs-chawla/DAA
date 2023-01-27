#include <bits/stdc++.h>
using namespace std;

bool cmp(vector<int> &a, vector<int> &b)
{
    return a[1] <= b[1];
}
int main()
{
    vector<vector<int>> v = {{1, 3}, {2, 6}, {4, 5},{3,4},{5,6}};
    sort(v.begin(), v.end(), cmp);

    int ans = 0;
    int freeAt = 0;
    for (int i = 0; i < v.size(); i++)
    {
        /* code */
        if (freeAt <= v[i][0])
        {
            ans++;
            freeAt = v[i][1];
        }
    }
    cout << ans;

    return 0;
}
