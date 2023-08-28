#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(vector<int> &stoneValue, int i, vector<int> &dp)
    {

        if (i == stoneValue.size())
            return 0;

        if (dp[i] != -1)
            return dp[i];

        int ans = INT_MIN;
        int total = 0;

        for (int X = 1; X <= 3; X++)
        {
            if (i + X - 1 >= stoneValue.size())
                break;

            total += stoneValue[i + X - 1];

            ans = max(ans, total - solve(stoneValue, i + X, dp));
        }

        return dp[i] = ans;
    }

    string stoneGameIII(vector<int> &stoneValue)
    {

        vector<int> dp(stoneValue.size() + 1, -1);
        int ans = solve(stoneValue, 0, dp);

        if (ans > 0)
            return "Alice";
        if (ans < 0)
            return "Bob";
        return "Tie";
    }
};