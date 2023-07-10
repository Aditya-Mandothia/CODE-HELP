#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int solve(vector<int>&nums,int curr,int prev, vector<vector<int>>&dp){

        if(curr>=nums.size())
        {
            return 0;
        }

        if(dp[curr][prev+1]!=-1)
        return dp[curr][prev+1];  //code is same we just shifter +1 with at every instance

        int include = 0;
        if(prev==-1 || nums[curr]>nums[prev])
        {
            include = 1 + solve(nums,curr+1,curr,dp);
        }
        
            int exclude = solve(nums,curr+1,prev,dp);
        

        int ans = max(include,exclude);
        dp[curr][prev+1]=ans;
        return dp[curr][prev+1];

    } 

    int solve2(vector<int>& nums)
    {
        int n = nums.size();
        vector<vector<int>>dp(n+5,vector<int>(n+5,0));

        for(int curr=n-1;curr>=0;curr--)
        {
            for(int prev=curr-1;prev>=-1;prev--) //because prev value goes from curr-1 to -1 or actually -1 to curr-1 in the recursive/top down approach
            {
                int include = 0;
                    if(prev==-1 || nums[curr]>nums[prev])
                    {
                        include = 1 + dp[curr+1][curr+1];
                    }
                    
                        int exclude = dp[curr+1][prev+1];
                    

                    int ans = max(include,exclude);

                    dp[curr][prev+1]=ans;
            }
        }

        return dp[0][0];
    }


    int lengthOfLIS(vector<int>& nums) {
        
        int n=nums.size();
        int curr=0;
        int prev=-1;
        // vector<vector<int>>dp(n,vector<int>(n+1,-1));
        // return solve(nums,curr,prev,dp);
        return solve2(nums);
    }
};