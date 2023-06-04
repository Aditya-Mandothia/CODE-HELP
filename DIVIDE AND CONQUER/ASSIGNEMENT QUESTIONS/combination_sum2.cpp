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
        if (i > index and candidates[i] == candidates[i - 1])
        {
            continue;
        }
        v.push_back(candidates[i]);
        combinationSumHelper(candidates, target - candidates[i], ans, v, i + 1);
        v.pop_back();
    }
}

vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
{
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> ans;
    vector<int> v;
    combinationSumHelper(candidates, target, ans, v, 0);
    return ans;
}

int main()
{
    vector<int> candidates = {2, 5, 2, 1, 2};
    int target = 5;

    vector<vector<int>> result = combinationSum2(candidates, target);

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