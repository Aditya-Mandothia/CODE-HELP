#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(vector<int> &prices, int i, bool buy, int &fee, vector<vector<int>> &dp)
    {

        if (i >= prices.size())
            return 0;

        if (dp[i][buy] != -1)
            return dp[i][buy];

        int maxProfit = 0;

        if (buy)
        {
            int ifBuy = -prices[i] + solve(prices, i + 1, 0, fee, dp);
            int ifSkip = 0 + solve(prices, i + 1, 1, fee, dp);
            maxProfit = max(ifBuy, ifSkip);
        }
        else
        {

            int ifSell = prices[i] + solve(prices, i + 1, 1, fee, dp) - fee;
            int ifSkip = 0 + solve(prices, i + 1, 0, fee, dp);
            maxProfit = max(ifSell, ifSkip);
        }

        return dp[i][buy] = maxProfit;
    }

    int maxProfit(vector<int> &prices, int fee)
    {
        vector<vector<int>> dp(prices.size() + 1, vector<int>(2, -1));
        return solve(prices, 0, 1, fee, dp);
    }
};