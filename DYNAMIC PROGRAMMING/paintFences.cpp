#include<bits/stdc++.h>
using namespace std;

int count_ways(int n,int k)
{
    if(n==1)
    {
        return k;
    }

    if(n==2)
    {
        return k*k;
    }

    int ans =  (count_ways(n-1,k) + count_ways(n-2,k))*(k-1); 
    return ans;
}

int countWays2(int n, int k, vector<int>&dp)
{
     if(n==1)
    {
        return k;
    }

    if(n==2)
    {
        return k*k;
    }

    if(dp[n]!= -1)
    return dp[n];

    dp[n] =  ((count_ways(n-1,k) + count_ways(n-2,k))*(k-1)); 
    return dp[n];


}

int countWays3(int n, int k)
{
    vector<int>dp(n+1,0);

    dp[1]=k;
    dp[2]=k*k;

    for(int i=3;i<=n;i++){
    dp[i] =  (dp[i-1] + dp[i-2])*(k-1); 
    }

    return dp[n];

}

int main()
{
    int n=4;
    int k=3;
    vector<int>dp(n+1,-1);

    cout<<countWays3(n,k);

return 0;
}