#include <bits/stdc++.h>
using namespace std;

bool solveMem(vector<int> &arr, int index, int sum, vector<vector<bool>> &dp)
{
    // base case
    if (sum == 0)
        return true;

    if (index == 0)
    {
        if (arr[index] == sum)
            return true;
        else
            return false;
    }

    if (dp[index][sum] != false)
    {
        return dp[index][sum];
    }

    if (arr[index] > sum)
        dp[index][sum] = solveMem(arr, index - 1, sum, dp);

    dp[index][sum] = solveMem(arr, index - 1, sum, dp) || solveMem(arr, index - 1, sum - arr[index], dp);

    return dp[index][sum];
}

bool solveTab(vector<int> &arr, int index, int sum)
{
    vector<vector<bool>> dp(index + 1, vector<bool>(sum, false));

    //sum is zero
    for (int i = 0; i <= index; i++)
    {

        dp[i][0] = true;
    }

    //sum is not zero and array is not empty
     for (int i = 1; i <= sum; i++)
    {

        dp[0][i] = true;
    }

    for(int i=1;i<=index;i++)
    {
        for(int j=1;j<=sum;j++)
        {
            
    if (arr[i] > j)
        dp[i][j] = dp[i- 1][j];

    dp[i][j] = dp[index - 1][j] || dp[i- 1][j - arr[i]];
        }
    }

    return dp[index][sum];


}

int main()
{

    vector<int> arr = { 3, 34, 4, 12, 5, 2 };
    int sum = 9;
    int n = 6;
    vector<vector<bool>> dp(n, vector<bool>(sum, false));

    cout << solveMem(arr, n - 1, sum, dp);

    return 0;
}