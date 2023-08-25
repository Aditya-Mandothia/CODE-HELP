#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solveOptimal(vector<int> &arr, vector<int> &lis)
    {
        if (arr.size() == 0)
            return 0;

        vector<int> ans;
        lis.push_back(1);

        ans.push_back(arr[0]);

        for (int i = 1; i < arr.size(); i++)
        {
            if (arr[i] > ans.back())
            {
                ans.push_back(arr[i]);
                lis.push_back(ans.size());
            }
            else
            {
                int index = lower_bound(ans.begin(), ans.end(), arr[i]) - ans.begin();
                ans[index] = arr[i];
                lis.push_back(index + 1);
            }
        }

        return ans.size();
    }

    int minimumMountainRemovals(vector<int> &nums)
    {

        vector<int> lis, lds;

        solveOptimal(nums, lis);
        reverse(nums.begin(), nums.end());
        solveOptimal(nums, lds);

        int largestMountain = INT_MIN;

        for (int i = 0; i < nums.size(); i++)
        {
            if (lis[i] == 1 || lds[nums.size() - i - 1] == 1)
                continue; // continue is for ignore

            largestMountain = max(largestMountain, lis[i] + lds[nums.size() - i - 1] - 1);
        }

        int minimumRemovals = nums.size() - largestMountain;
        return minimumRemovals;
        // return 0;
    }
};