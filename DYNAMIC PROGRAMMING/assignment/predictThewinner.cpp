#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(vector<int> &nums, int start, int end, vector<vector<int>> &dp)
    {

        if (start == end)
            return nums[start];

        if (dp[start][end] != -1)
            return dp[start][end];

        int diffStart = nums[start] - solve(nums, start + 1, end, dp);
        int diffEnd = nums[end] - solve(nums, start, end - 1, dp);

        return dp[start][end] = max(diffStart, diffEnd);
    }

    bool predictTheWinner(vector<int> &nums)
    {

        vector<vector<int>> dp(nums.size(), vector<int>(nums.size(), -1));
        return solve(nums, 0, nums.size() - 1, dp) >= 0;
    }
};