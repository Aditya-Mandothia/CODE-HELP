#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(vector<int> &piles, int i, int M, int alice, vector<vector<vector<int>>> &dp)
    {

        if (i == piles.size())
            return 0;

        if (dp[i][M][alice] != -1)
        {
            return dp[i][M][alice];
        }

        int ans = alice ? INT_MIN : INT_MAX;
        int total = 0;

        for (int X = 1; X <= 2 * M; X++)
        {
            if (i + X - 1 >= piles.size())
                break;
            total += piles[X + i - 1];

            if (alice)
            {
                ans = max(ans, total + solve(piles, i + X, max(X, M), !alice, dp));
            }
            else
            {
                ans = min(ans, solve(piles, i + X, max(X, M), !alice, dp));
            }
        }

        return dp[i][M][alice] = ans;
    }

    int stoneGameII(vector<int> &piles)
    {
        vector<vector<vector<int>>> dp(piles.size() + 1, vector<vector<int>>(piles.size() + 1, vector<int>(2, -1)));
        return solve(piles, 0, 1, true, dp);
    }
};