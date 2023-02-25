#include <bits/stdc++.h>
using namespace std;

int findDup(vector<int> arr)
{
    int ans = -1;

    for (int i = 0; i < arr.size(); i++)
    {
        int index = abs(arr[i]);

        if (arr[index] < 0) //{1, -3, -4, -2, -2};
        {
            ans = index;
            break;
        }

        arr[index] *= -1;
    }

    return ans;
}

int findDup2(vector<int>arr)
{   
    while(arr[0] != arr[arr[0]]){
        swap(arr[0],arr[arr[0]]);
    }


    return arr[0];
}

int main()
{

    vector<int> arr = {1, 2, 3, 4, 2};
    cout << findDup2(arr);

    return 0;
}