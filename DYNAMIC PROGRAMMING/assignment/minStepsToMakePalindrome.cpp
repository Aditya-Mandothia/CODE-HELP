#include<bits/stdc++.h>
using namespace std;

// minimum insertion steps to make a string palindromic

class Solution {
public:

    int solve2(string &a, string &b)
    {
        int n1 = a.length();
        int n2 = b.length();

        vector<vector<int>>dp(n1+1,vector<int>(n2+1,0));

        for(int i=n1-1;i>=0;i--)
        {
            for(int j=n2-1;j>=0;j--)
            {   
                if(i==n1 and j==n2)
                continue;

                int ans=0;

                if(a[i]==b[j])
                {
                        ans = 1 + dp[i+1][j+1];
                }
                else{
                        ans =  max(dp[i][j+1],dp[i+1][j]);
                }

                dp[i][j]=ans;
            }
        }

        return dp[0][0];
    }

    int minInsertions(string s) {

        int intialSize = s.length();
        string initial = s;

        reverse(s.begin(),s.end());
        string reverse = s;
        int lpsSize = solve2(initial,reverse);

        return intialSize - lpsSize;
        
    }
};