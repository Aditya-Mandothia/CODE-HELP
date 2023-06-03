#include <bits/stdc++.h>
using namespace std;

void combinationSumHelper(vector<int> &candidates, int target, vector<vector<int>> &ans, vector<int> &v, int index)
{
    if (target == 0)
    {
        ans.push_back(v);
        return;
    }

    if (target < 0)
    {
        return;
    }

    for (int i = index; i < candidates.size(); i++)
    {
        v.push_back(candidates[i]);
        combinationSumHelper(candidates, target - candidates[i], ans, v, i);
        v.pop_back();
    }
}

vector<vector<int>> combinationSum1(vector<int> &candidates, int target)
{
    vector<vector<int>> ans;
    vector<int> v;
    combinationSumHelper(candidates, target, ans, v, 0);
    return ans;
}

int main()
{
    vector<int> candidates = {2, 3, 5};
    int target = 8;

    vector<vector<int>> result = combinationSum1(candidates, target);

    for (int i = 0; i < result.size(); i++)
    {
        for (auto x : result[i])
        {
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}