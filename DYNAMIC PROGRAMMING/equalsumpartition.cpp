#include <bits/stdc++.h>
using namespace std;

bool find(vector<int> &arr, int n, int sum, vector<vector<bool>> &dp)
{
    if (n == 0)
    {
        if (arr[n] == sum)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    if (sum < 0)
        return false;

    if (sum == 0)
        return true;

    if (dp[n][sum])
    {
        return dp[n][sum];
    }

    bool include = find(arr, n - 1, sum - arr[n], dp);

    bool exclude = find(arr, n - 1, sum, dp);

    dp[n][sum] = include || exclude;

    return dp[n][sum];
}

int main()
{

    vector<int> arr = {1,5,11,5};
    int sum = 22;
    int ssum = 11;
    vector<vector<bool>> dp(4, vector<bool>(ssum + 1, false));
    cout << find(arr, 3, ssum, dp);
    return 0;
}