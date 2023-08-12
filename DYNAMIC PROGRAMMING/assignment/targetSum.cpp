#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // int solve(vector<int>&nums,int target,int i, map<pair<int,int>,int>&dp){

    //     if(i==nums.size()){
    //         if(target==0)
    //         return 1;
    //         else
    //         return 0;
    //     }

    //     if(dp.find({i,target}) != dp.end())
    //     return dp[{i,target}];

    //     //if we add the number
    //     int adding = solve(nums,target - nums[i],i+1, dp);

    //     int subtracting = solve(nums,target + nums[i],i+1, dp);

    //     return dp[{i,target}] = adding + subtracting;

    // }

    int solve2(vector<int> &nums, int target)
    {
        // tabulation method

        map<pair<int, int>, int> dp;

        dp[{nums.size(), 0}] = 1;

        int total = 0;
        for (auto x : nums)
        {
            total += x;
        }

        for (int i = nums.size() - 1; i >= 0; i--)
        {
            for (int target = -total; target <= total; target++)
            {
                int adding = dp.find({i + 1, target - nums[i]}) != dp.end() ? dp[{i + 1, target - nums[i]}] : 0;

                int subtracting = dp.find({i + 1, target + nums[i]}) != dp.end() ? dp[{i + 1, target + nums[i]}] : 0;

                dp[{i, target}] = adding + subtracting;
            }
        }

        return dp[{0, target}];
    }

    int findTargetSumWays(vector<int> &nums, int target)
    {

        map<pair<int, int>, int> dp;
        return solve2(nums, target);
    }
};