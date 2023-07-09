#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(string a, string b, int i, int j)
    {
        // base case
        if (i == a.length())
            return 0;

        if (j == b.size())
            return 0;

        int ans = 0;
        if (a[i] == b[j])
        {
            ans = 1 + solve(a, b, i + 1, j + 1);
        }
        else
        {
            ans = +max(solve(a, b, i, j + 1), solve(a, b, i + 1, j));
        }

        return ans;
    }

    int solve1(string &a, string &b, int i, int j, vector<vector<int>> &dp)
    {
        // base case
        if (i == a.length())
            return 0;

        if (j == b.length())
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        int ans = 0;
        if (a[i] == b[j])
        {
            ans = 1 + solve1(a, b, i + 1, j + 1, dp);
        }
        else
        {
            ans = +max(solve1(a, b, i, j + 1, dp), solve1(a, b, i + 1, j, dp));
        }

        dp[i][j] = ans;
        return dp[i][j];
    }

    int solve2(string &a, string &b)
    {
        int n1 = a.length();
        int n2 = b.length();

        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));

        for (int i = n1 - 1; i >= 0; i--)
        {
            for (int j = n2 - 1; j >= 0; j--)
            {
                if (i == n1 and j == n2)
                    continue;

                int ans = 0;

                if (a[i] == b[j])
                {
                    ans = 1 + dp[i + 1][j + 1];
                }
                else
                {
                    ans = max(dp[i][j + 1], dp[i + 1][j]);
                }

                dp[i][j] = ans;
            }
        }

        return dp[0][0];
    }

    int longestCommonSubsequence(string text1, string text2)
    {
        // int i=0;
        // int j=0;
        // vector<vector<int>>dp(text1.length(),vector<int>(text2.length(),-1));

        // return solve1(text1,text2,i,j,dp);
        return solve2(text1, text2);
    }
};