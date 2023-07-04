#include <bits/stdc++.h>
using namespace std;

int solveRec(int wt[], int val[], int index, int maxWeight)
{

    if (index == 0)
    {
        if (wt[index] <= maxWeight)
        {
            return val[index];
        }
        else
        {
            return 0;
        }
    }

    int include = 0;

    if (wt[index] <= maxWeight)
    {
        include = val[index] + solveRec(wt, val, index - 1, maxWeight - wt[index]);
    }

    int exclude = 0 + solveRec(wt, val, index - 1, maxWeight);

    int ans = max(include, exclude);

    return ans;
}

int solveMem(int wt[], int val[], int index, int maxWeight, vector<vector<int>> &dp)
{
    if (index == 0)
    {
        if (wt[index] <= maxWeight)
        {
            return val[index];
        }
        else
        {
            return 0;
        }
    }

    if (dp[index][maxWeight] != -1)
    {
        return dp[index][maxWeight];
    }

    int include = 0;

    if (wt[index] <= maxWeight)
    {
        include = val[index] + solveMem(wt, val, index - 1, maxWeight - wt[index], dp);
    }

    int exclude = 0 + solveMem(wt, val, index - 1, maxWeight, dp);

    dp[index][maxWeight] = max(include, exclude);

    return dp[index][maxWeight];
}

int solveTab(int wt[], int val[], int n, int maxWeight)
{

    vector<vector<int>> dp(n, vector<int>(maxWeight + 1, 0));

    for (int w = wt[0]; w <= maxWeight; w++)
    {
        if (wt[0] <= maxWeight)
            dp[0][w] = val[0];
        else
        {
            dp[0][w] = 0;
        }
    }

    for (int i = 1; i < n; i++)
    {
        for (int wt1 = 0; wt1 <= maxWeight; wt1++)
        {

            int include = 0;

            if (wt[i] <= wt1)
            {
                include = val[i] + dp[i- 1][wt1 - wt[i]];
            }

            int exclude = 0 + dp[i- 1][wt1];

            dp[i][wt1] = max(include, exclude);

        }
    }

    cout<<"worked";

    return dp[n-1][maxWeight];
}

int main()
{
    int wt[] = {4, 5, 1};
    int val[] = {1, 2, 3};
    int n = 3;
    int maxWeight = 4;

    // vector<vector<int>> dp(n, vector<int>(maxWeight + 1, -1));

    // cout << solveRec(wt, val, n - 1, maxWeight);
    // cout << solveMem(wt, val, n - 1, maxWeight, dp);
    cout << solveTab(wt, val, n, maxWeight);

    return 0;
}