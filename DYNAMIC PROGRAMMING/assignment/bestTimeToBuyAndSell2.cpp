#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        vector<vector<int>> dp(prices.size() + 1, vector<int>(2, 0));

        for (int i = prices.size() - 1; i >= 0; i--)
        {
            for (int buy = 0; buy <= 1; buy++)
            {
                int profit = 0;

                if (buy == 1)
                {
                    int buyProfit = -prices[i] + dp[i + 1][0];
                    int skipProfit = dp[i + 1][1];
                    profit = max(buyProfit, skipProfit);
                }
                else
                {

                    int sellProfit = prices[i] + dp[i + 1][1];
                    int skipProfit = dp[i + 1][0];
                    profit = max(sellProfit, skipProfit);
                }

                dp[i][buy] = profit;
            }
        }

        return dp[0][1];
    }
};