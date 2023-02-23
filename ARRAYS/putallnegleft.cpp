#include <bits/stdc++.h>
using namespace std;

void allnegleft(vector<int> &arr)
{   
    //Dutch National Algorithm

    int l = 0;
    int h = arr.size() - 1;

    while (l < h)
    {
        if (arr[l] < 0)
        {
            l++;
        }
        else if (arr[h] > 0)
        {
            h--;
        }
        else
        {
            swap(arr[l],arr[h]);
        }
    }
}

void printarr(vector<int> &arr)
{
    for( int x : arr)
    {
        cout<<x<<" ";
    }
}

int main()
{

    vector<int> arr = {10, -2, 4, -6, 5};
    allnegleft(arr);
    printarr(arr);

    return 0;
}
