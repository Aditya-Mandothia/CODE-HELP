#include <bits/stdc++.h>
using namespace std;

void permuteuniquehelper(vector<int> &nums, vector<vector<int>> &ans, int start)
{

    if (start == nums.size())
    {
        ans.push_back(nums);
        return;
    }

    unordered_map<int, bool> visited;

    for (int i = start; i < nums.size(); i++)
    {
        if (visited.find(nums[i]) != visited.end())
        {
            continue; // that is skip this digit
        }

        visited[nums[i]] = true;
        swap(nums[i], nums[start]);
        permuteuniquehelper(nums, ans, start + 1);
        swap(nums[i], nums[start]); // regenerate original number.
    }
}

vector<vector<int>> permuteunique(vector<int> &nums)
{
    vector<vector<int>> ans;
    permuteuniquehelper(nums, ans, 0);
    return ans;
}

int main()
{

    vector<int> nums = {1, 1, 2};
    vector<vector<int>> res = permuteunique(nums);

    for (int i = 0; i < res.size(); i++)
    {
        for (auto x : res[i])
        {
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}