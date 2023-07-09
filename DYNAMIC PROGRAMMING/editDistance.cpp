#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(string &a, string &b, int i, int j)
    {
        if (i == a.length())
        {
            return b.length() - j;
        }

        if (j == b.length())
        {
            return a.length() - i;
        }

        int ans = 0;

        if (a[i] == b[j])
        {
            ans = solve(a, b, i + 1, j + 1);
        }
        else
        {
            int insert = 1 + solve(a, b, i, j + 1);
            int deleted = 1 + solve(a, b, i + 1, j);
            int replace = 1 + solve(a, b, i + 1, j + 1);

            ans = min(insert, min(deleted, replace));
        }

        return ans;
    }

    int solve1(string &a, string &b, int i, int j, vector<vector<int>> &dp)
    {
        if (i == a.length())
        {
            return b.length() - j;
        }

        if (j == b.length())
        {
            return a.length() - i;
        }

        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }

        int ans = 0;

        if (a[i] == b[j])
        {
            ans = solve1(a, b, i + 1, j + 1, dp);
        }
        else
        {
            int insert = 1 + solve1(a, b, i, j + 1, dp);
            int deleted = 1 + solve1(a, b, i + 1, j, dp);
            int replace = 1 + solve1(a, b, i + 1, j + 1, dp);

            ans = min(insert, min(deleted, replace));
        }

        dp[i][j] = ans;
        return dp[i][j];
    }

    int solve2(string &a, string &b)
    {
        int n1 = a.length();
        int n2 = b.length();

        vector<vector<int>> dp(n1 + 5, vector<int>(n2 + 5, -1));

        for (int j = 0; j <= n2; j++)
        {
            dp[n1][j] = n2 - j;
        }

        for (int i = 0; i <= n1; i++)
        {
            dp[i][n2] = n1 - i;
        }

        for (int i = n1 - 1; i >= 0; i--)
        {
            for (int j = n2 - 1; j >= 0; j--)
            {
                int ans = 0;

                if (a[i] == b[j])
                {
                    ans = dp[i + 1][j + 1];
                }
                else
                {
                    int insert = 1 + dp[i][j + 1];
                    int deleted = 1 + dp[i + 1][j];
                    int replace = 1 + dp[i + 1][j + 1];

                    ans = min(insert, min(deleted, replace));
                }

                dp[i][j] = ans;
            }
        }

        return dp[0][0];
    }

    int minDistance(string word1, string word2)
    {

        // int n1 = word1.length();
        // int n2 = word2.length();
        // vector<vector<int>>dp(n1+5,vector<int>(n2+5,-1));
        // return solve1(word1,word2,0,0,dp);
        return solve2(word1, word2);
    }
};