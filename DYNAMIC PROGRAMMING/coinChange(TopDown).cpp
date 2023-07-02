// class Solution {
// public:
//     int recSolve(vector<int>&coins,int amount,vector<int>&dp){

//         //base case
//         if(amount == 0)
//         {
//             return 0;
//         }

//         // negative base case
//         if(amount < 0)
//         {
//             return INT_MAX;
//         }

//         if(dp[amount]!= -1)
//         {
//             return dp[amount];
//         }

//         int mini = INT_MAX;

//         for(int i=0;i<coins.size();i++)
//         {
//             int ans = recSolve(coins,amount - coins[i], dp);

//             if(ans!= INT_MAX){
//                 mini = min(mini,ans + 1);
//             }
//         }

//         dp[amount] = mini; //matlab har amount pe minimum coins kitne the

//         return mini;

//     }

//     int coinChange(vector<int>& coins, int amount) {

//         // int ans = recSolve(coins,amount);
//         // if(ans!= INT_MAX)
//         // {
//         //     return ans;
//         // }
//         // else{
//         //     return -1;
//         // }

//         vector<int>dp(amount+1,-1);
//         int ans = recSolve(coins,amount,dp);

//         if(ans!= INT_MAX)
//         {
//             return ans;
//         }
//         else{
//             return -1;
//         }
        
//     }
// };