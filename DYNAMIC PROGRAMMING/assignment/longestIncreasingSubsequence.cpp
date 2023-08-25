#include <bits/stdc++.h>
using namespace std;

int solveOptimal(vector<int> &arr)
{
    if (arr.size() == 0)
        return 0;

    vector<int> ans;

    ans.push_back(arr[0]);

    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i] > ans.back())
        {
            ans.push_back(arr[i]);
        }
        else
        {
            int index = lower_bound(ans.begin(), ans.end(), arr[i]) - ans.begin();
            ans[index] = arr[i];
        }
    }

    return ans.size();
}
