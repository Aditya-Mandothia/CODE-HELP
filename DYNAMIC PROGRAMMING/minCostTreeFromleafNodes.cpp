#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(vector<int> &arr, map<pair<int, int>, int> &maxi, int left, int right)
    {
        if (left == right)
        {
            return 0;
        }

        int ans = INT_MAX;

        for (int i = left; i < right; i++)
        {
            ans = min(ans, maxi[{left, i}] * maxi[{i + 1, right}] + solve(arr, maxi, left, i) + solve(arr, maxi, i + 1, right));
        }

        return ans;
    }

    int solve1(vector<int> &arr, map<pair<int, int>, int> &maxi, int left, int right, vector<vector<int>> &dp)
    {
        if (left == right)
        {
            return 0;
        }

        if (dp[left][right] != -1)
        {
            return dp[left][right];
        }

        int ans = INT_MAX;

        for (int i = left; i < right; i++)
        {
            ans = min(ans, maxi[{left, i}] * maxi[{i + 1, right}] + solve1(arr, maxi, left, i, dp) + solve1(arr, maxi, i + 1, right, dp));
        }

        return dp[left][right] = ans;
    }

    int solve2(vector<int> &arr, map<pair<int, int>, int> &maxi)
    {
        int n = arr.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for (int left = n - 1; left >= 0; left--)
        {
            for (int right = 0; right <= n - 1; right++)
            {
                if (left >= right)
                    continue;
                {
                    int ans = INT_MAX;

                    for (int i = left; i < right; i++)
                    {
                        ans = min(ans, maxi[{left, i}] * maxi[{i + 1, right}] + dp[left][i] + dp[i + 1][right]);
                    }

                    dp[left][right] = ans;
                }
            }
        }

        return dp[0][n - 1];
    }

    int mctFromLeafValues(vector<int> &arr)
    {
        map<pair<int, int>, int> maxi;

        for (int i = 0; i < arr.size(); i++)
        {
            maxi[{i, i}] = arr[i];

            for (int j = i + 1; j < arr.size(); j++)
            {
                maxi[{i, j}] = max(arr[j], maxi[{i, j - 1}]);
            }
        }

        int n = arr.size();

        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

        // int ans = solve1(arr,maxi,0,n-1,dp);
        int ans = solve2(arr, maxi);
        return ans;
    }
};
