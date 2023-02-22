#include <bits/stdc++.h>
using namespace std;

int findPivot(vector<int> arr)
{
    int s = 0;
    int e = arr.size() - 1;

    int mid = s + (e - s) / 2;

    while (s <= e)
    {
        if (s == e)
        {
            return s;
        }

        if (mid <= e and arr[mid] > arr[mid + 1])
            return mid;

        if (mid - 1 >= s and arr[mid - 1] > arr[mid])
            return mid - 1;

        if (arr[s] > arr[mid])
            e = mid - 1;
        else
            s = mid + 1;

        mid = s + (e - s) / 2;
    }

    return -1;
}

int binarysearch(vector<int> arr, int s, int e, int target)
{
    int mid = s + (e - s) / 2;


    while (s <= e)
    {
        if (arr[mid] == target)
            return arr[mid];

        else if (arr[mid] < target)
        {
            s = mid + 1;
        }
        else
            e = mid - 1;

        mid = s + (e - s) / 2;
       
    }

    return -1;
}

int pivotsearch(vector<int> arr, int target)
{
    int pivot = findPivot(arr);

    if ( arr[0] <= target)
    {
        int s1 = 0;
        int e1 = pivot - 1;

        return binarysearch(arr, s1, e1, target);
    }
    else
    {
        int s2 = pivot + 1;
        int e2 = arr.size() - 1;
        return binarysearch(arr, s2, e2, target);
    }

}

int main()
{
    vector<int> arr = {8, 9, 10, 2, 4, 6};
    int target = 4;

    cout<<pivotsearch(arr, target);
    // cout<<findPivot(arr);

    return 0;
}