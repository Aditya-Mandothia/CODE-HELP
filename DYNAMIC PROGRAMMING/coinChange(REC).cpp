// class Solution {
// public:
//     int recSolve(vector<int>&coins,int amount){

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

//         int mini = INT_MAX;

//         for(int i=0;i<coins.size();i++)
//         {
//             int ans = recSolve(coins,amount - coins[i]);

//             if(ans!= INT_MAX){
//                 mini = min(mini,ans + 1);
//             }
//         }

//         return mini;

//     }

//     int coinChange(vector<int>& coins, int amount) {

//         int ans = recSolve(coins,amount);
//         if(ans!= INT_MAX)
//         {
//             return ans;
//         }
//         else{
//             return -1;
//         }
        
//     }
// };