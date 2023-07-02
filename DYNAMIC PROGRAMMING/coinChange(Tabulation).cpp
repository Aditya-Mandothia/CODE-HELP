// int coinChangeTab(vector<int>&coins, int amount)
//     {
//         vector<int>dp(amount+1, INT_MAX);

//         dp[0]=0;

//         for(int target = 1; target<=amount; target++)
//         {
//             int mini = INT_MAX;

//             for(int i=0;i<coins.size();i++)
//             {
//                 if(target-coins[i] >= 0)
//                 {
//                     int ans = dp[target-coins[i]];

//                     if(ans!=INT_MAX)
//                     {
//                         mini = min(ans+1,mini);
//                     }
//                 }
//             }

//             dp[target] = mini;
//         }

//         return dp[amount];
//     }