#include <bits/stdc++.h>
using namespace std;

long merge(vector<int> arr, vector<int> temp, int start, int mid, int end)
{

    int i = start;
    int j = mid + 1; // for two arrays (sorted)
    int k = start;   // adding in main array
    long c = 0;      // for counting inversion

    while (i <= mid and j <= end)
    {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
        {
            temp[k++] = arr[j++];
            c += mid - i + 1;
        }
    }

    while (i <= mid)
        temp[k++] = arr[i++];
    while (j <= end)
        temp[k++] = arr[j++];

    while (start <= end)
    {
        arr[start] = temp[start];
        ++start;
    }

    return c;
}

long mergeSort(vector<int> &arr, vector<int> &temp, int start, int end)
{

    if (start >= end)
        return 0;

    int mid = start + (end - start) / 2;
    long c = 0;

    c += mergeSort(arr, temp, start, mid);
    c += mergeSort(arr, temp, mid + 1, end);
    c += merge(arr, temp, start, mid, end);

    return c;
}

long countInversions(vector<int> arr)
{
    long c = 0;
    vector<int> temp(arr.size(), 0);
    c = mergeSort(arr, temp, 0, arr.size() - 1);
    return c;
}
int main()
{

    vector<int> arr = {8, 4, 2, 1};

    // count inversions

    cout << countInversions(arr);

    return 0;
}