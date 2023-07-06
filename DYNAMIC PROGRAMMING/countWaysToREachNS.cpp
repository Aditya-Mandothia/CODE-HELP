#include<bits/stdc++.h>
using namespace std;

int climbStairs(int n, vector<int>&dp) {

        if(n==0 || n==1)
        {
            dp[n]=1;
            return dp[n];
        }

        if(dp[n]!=-1)
        {
            return dp[n];
        }

        dp[n]= climbStairs(n-1,dp) + climbStairs(n-2,dp); 

        return dp[n];
        
    }

int climbStairs1(int n)
{
    vector<int>dp(n+1,0);

    dp[0] = 1;
    dp[1] = 1;

    for(int i=2;i<=n;i++)
    {
        dp[i]= dp[i-1]+ dp[i-2]; 
    }

    return dp[n];
}

int climbStairs2(int n)
{
    // vector<int>dp(n+1,0);

   int prev1 = 1;
   int prev2 = 1;


    int curr=0;
    for(int i=2;i<=n;i++)
    {
        curr= prev1 + prev2;
        prev1 = prev2;
        prev2 = curr; 
    }

    return curr ;
}


int main()
{   
    vector<int>dp(4,-1);

    cout<<climbStairs2(3);

return 0;
}