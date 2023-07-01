// class Solution {
// public: 

//     int TopDownSolve(int n, vector<int>&dp)
//     {

//         if(n == 0 || n==1)
//         return n;

//         if(dp[n]!= -1)
//         return dp[n];

//         dp[n]= TopDownSolve(n-1,dp) + TopDownSolve(n-2,dp);
//         return dp[n];
//     }

//     int bottomUp(int n)
//     {
//         vector<int> dp(n+1,-1);

//         dp[0] = 0;
//         if(n==0)
//         return dp[0];

//         dp[1] = 1;
        
//         if(n==1)
//         return dp[1];

//         for(int i=2;i<=n;i++)
//         {
//             dp[i] = dp[i-1] + dp[i-2];
//         }

//         return dp[n];
//     }

//     int space_optimized_solution(int n)
//     {
//         //  vector<int> dp(n+1,-1);

//         int prev2 = 0;
//         int prev1 = 1;

//         if(n==0)
//         return prev2;

//         if(n==1)
//         return prev1;

//         int curr=0;



//         for(int i=2;i<=n;i++)
//         {
//             // dp[i] = dp[i-1] + dp[i-2];
//             curr = prev1 + prev2;
//             prev2 = prev1;
//             prev1 = curr;
//         }

//         // return dp[n];
//         return curr;
//     }



//     int fib(int n) {

//         // vector<int>dp(n+1,-1);
//         // int ans = TopDownSolve(n,dp);
//         // int ans = bottomUp(n);
//         return space_optimized_solution(n);
        
//     }
// };