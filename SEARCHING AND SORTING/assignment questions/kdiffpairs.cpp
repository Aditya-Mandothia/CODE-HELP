#include <bits/stdc++.h>
using namespace std;

// vector<vector<int>> kdiffpairs(vector<int> arr, int k)
// {
//     vector<vector<int>> answer;

//     sort(arr.begin(), arr.end());

//     int i = 0;
//     int j = 1;

//     while (j < arr.size())
//     {
//         vector<int> temp;

//         if (arr[j] - arr[i] == k)
//         {
//             temp.push_back(arr[j]);
//             temp.push_back(arr[i]);
//             answer.push_back(temp);
//             i++;
//             j++;
//         }
//         else if (arr[j] - arr[i] < k)
//         {
//             j++;
//         }
//         else
//         {
//             i++;
//         }

//         if(i==j)
//         j++;
//     }

//     return answer;
// }

int bs(vector<int> &arr, int start, int key)
{
    int end = arr.size()-1;

    while (start <= end)
    {
        int mid = (start + end) / 2;

        if (arr[mid] == key)
            return 1;
        else if (arr[mid] < key)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }

    return -1;
}

int kdiffpairs2(vector<int> &arr, int k)
{
    sort(arr.begin(), arr.end());
    set<pair<int, int>> ans;

    for (int i = 0; i < arr.size(); i++)
    {
        if (bs(arr, i + 1, arr[i] + k) != -1)
        {
            ans.insert({arr[i], arr[i] + k});
        }
    }

    return ans.size();
}
int main()
{

    vector<int> a = {1, 2, 3, 4, 5};

    // vector<vector<int>> pairs = kdiffpairs(a, 2);

    // cout << "The unique pairs with difference as 'k' are: " << endl;

    // for (auto x : pairs)
    // {
    //     for (int i = 0; i < 2; i++)
    //     {
    //         cout << x[i] << " ";
    //     }
    //     cout << endl;
    // }

    cout << kdiffpairs2(a, 2);

    return 0;
}