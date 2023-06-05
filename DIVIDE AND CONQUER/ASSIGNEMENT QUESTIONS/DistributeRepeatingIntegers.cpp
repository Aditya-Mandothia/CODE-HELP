#include <bits/stdc++.h>
using namespace std;

bool canDistributeHelper(vector<int> &counts, vector<int> &quantity, int ithcustomer)
{

    if (ithcustomer == quantity.size())
    {
        return true;
    }

    for (int i = 0; i < counts.size(); i++)
    {
        if (counts[i] >= quantity[ithcustomer])
        {
            counts[i] -= quantity[ithcustomer];

            if (canDistributeHelper(counts, quantity, ithcustomer + 1))
            {
                return true;
            }

            counts[i] += quantity[ithcustomer];
        }
    }

    return false; // edge case, for as we reversed the quantity array, it the customer with the highest requirement doesnt get the requirements fulfilled we will itterate overall all and can get false answer way faster eg, taking 5
}

bool canDistribute(vector<int> &nums, vector<int> &quantity)
{

    unordered_map<int, int> countMap;
    for (auto num : nums)
    {
        countMap[num]++;
    }

    vector<int> counts;
    for (auto it : countMap)
    {
        counts.push_back(it.second);
    }

    sort(quantity.rbegin(), quantity.rend());

    return canDistributeHelper(counts, quantity, 0);
}

int main()
{
    vector<int> nums = {1, 1, 2, 2, 2, 2, 3, 3};
    vector<int> quantity = {2, 3, 2};

    cout << canDistribute(nums, quantity);

    return 0;
}