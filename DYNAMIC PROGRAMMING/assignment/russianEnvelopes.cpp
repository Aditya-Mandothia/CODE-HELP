#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // int solve(vector<vector<int>>&envelopes,int prev,int i, vector<vector<int>>&dp){

    //     if(i==envelopes.size())
    //     {
    //         return 0;
    //     }

    //     if(dp[prev+1][i]!=-1)
    //     return dp[prev+1][i];

    //     int ans=0;

    //     int include = INT_MIN;

    //     if(prev==-1 || envelopes[prev][0] < envelopes[i][0] and envelopes[prev][1] < envelopes[i][1] )
    //     {
    //         include = 1 + solve(envelopes,i,i+1, dp);
    //     }

    //     int exclude = 0 + solve(envelopes,prev,i+1, dp);

    //     ans = max(include,exclude);

    //     return dp[prev+1][i]=ans;

    // }

    static bool comp(vector<int> &a, vector<int> &b)
    {
        if (a[0] == b[0])
            return a[1] > b[1];
        return a[0] < b[0];
    }

    int solveOptimal(vector<vector<int>> &arr)
    {
        sort(arr.begin(), arr.end(), comp);

        if (arr.size() == 0)
            return 0;

        vector<int> ans;

        ans.push_back(arr[0][1]);

        for (int i = 1; i < arr.size(); i++)
        {
            if (arr[i][1] > ans.back())
            {
                ans.push_back(arr[i][1]);
            }
            else
            {
                int index = lower_bound(ans.begin(), ans.end(), arr[i][1]) - ans.begin();
                ans[index] = arr[i][1];
            }
        }

        return ans.size();
    }

    int maxEnvelopes(vector<vector<int>> &envelopes)
    {
        // int i=0;
        // int prev=-1;
        // sort(envelopes.begin(),envelopes.end());
        // vector<vector<int>>dp(envelopes.size()+1,vector<int>(envelopes.size()+1,-1));
        // return solve(envelopes,prev,i,dp);

        return solveOptimal(envelopes);
    }
};