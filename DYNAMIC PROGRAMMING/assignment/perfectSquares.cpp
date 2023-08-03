#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numSquaresHelper(int n)
    {

        // if(n==0) return 1;
        // if(n<0) return 0;

        vector<int> dp(n + 10, -1);
        dp[0] = 1;

        for (int i = 1; i <= n; i++)
        {
            int ans = INT_MAX;
            int start = 1;
            int end = sqrt(i);

            while (start <= end)
            {
                int perfectSquare = start * start;
                int numberOfPerfectSquare = 1 + dp[i - perfectSquare];

                if (numberOfPerfectSquare < ans)
                {
                    ans = numberOfPerfectSquare;
                }

                start++;
            }
            dp[i] = ans;
        }

        return dp[n];
    }

    int numSquares(int n)
    {
        return numSquaresHelper(n) - 1;
    }
};