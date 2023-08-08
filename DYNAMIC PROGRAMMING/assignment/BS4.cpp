#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(vector<int> &prices, int i, bool buy, int limit, vector<vector<vector<int>>> &dp)
    {

        if (i >= prices.size() || limit == 0)
            return 0;

        if (dp[i][buy][limit] != -1)
            return dp[i][buy][limit];

        int maxProfit = 0;

        if (buy)
        {
            int ifBuy = -prices[i] + solve(prices, i + 1, 0, limit, dp);
            int ifSkip = 0 + solve(prices, i + 1, 1, limit, dp);

            maxProfit = max(ifBuy, ifSkip);
        }
        else
        {

            int ifSell = prices[i] + solve(prices, i + 1, 1, limit - 1, dp);
            int ifSkip = 0 + solve(prices, i + 1, 0, limit, dp);

            maxProfit = max(ifSell, ifSkip);
        }

        return dp[i][buy][limit] = maxProfit;
    }

    int maxProfit(int k, vector<int> &prices)
    {
        vector<vector<vector<int>>> dp(prices.size(), vector<vector<int>>(2, vector<int>(k + 1, -1)));
        return solve(prices, 0, 1, k, dp);
    }
};