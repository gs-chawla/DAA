#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int find(int idx, vector<vector<int>> &job, vector<int> &startTime, int n, vector<int> &dp)
    {
        if (idx >= n)
        {
            return 0;
        }
        if (dp[idx] != -1)
            return dp[idx];

        int index = lower_bound(startTime.begin(), startTime.end(), job[idx][1]) - startTime.begin();

        int pick = job[idx][2] + find(index, job, startTime, n, dp);
        int notPick = find(idx + 1, job, startTime, n, dp);

        return dp[idx] = max(pick, notPick);
    }
    int jobScheduling(vector<int> &startTime, vector<int> &endTime, vector<int> &profit)
    {
        int n = startTime.size();
        vector<vector<int>> job;
        vector<int> dp(n, -1);
        for (int i = 0; i < n; i++)
        {
            job.push_back({startTime[i], endTime[i], profit[i]});
        }

        sort(job.begin(), job.end());
        sort(startTime.begin(), startTime.end());
        return find(0, job, startTime, n, dp);
    }
};