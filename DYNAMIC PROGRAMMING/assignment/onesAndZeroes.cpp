#include<bits/stdc++.h>
using namespace std;
class Solution {
public:

    void convertStrstoNumStrs(vector<pair<int,int>>&numStrs,vector<string>&strs){

        for(auto str : strs)
        {
            int zeroes = 0;
            int ones = 0;

            for(auto ch:str)
            {
                if(ch == '0') zeroes++;
                else ones++;
            }

            numStrs.push_back({zeroes,ones});
        }

    } 

    int solve(vector<pair<int,int>>&numStrs,int i,int m,int n,vector<vector<vector<int>>>&dp){

        if(i==numStrs.size()) return 0;

        if(dp[i][m][n] != -1) return dp[i][m][n];

        int zeroes = numStrs[i].first;
        int ones = numStrs[i].second;

        int include = 0;
        int exclude = 0;

        if(m-zeroes >=0 and n-ones>=0)
        {
            include = 1 + solve(numStrs,i+1,m-zeroes,n-ones,dp);
        }

        exclude = solve(numStrs,i+1,m,n,dp);

        return dp[i][m][n]=max(include,exclude);

    }



    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<pair<int,int>>numStrs;
        convertStrstoNumStrs(numStrs,strs);
        vector<vector<vector<int>>>dp(strs.size(),vector<vector<int>>(m+1,vector<int>(n+1,-1)));
        return solve(numStrs,0,m,n,dp);
    }
};