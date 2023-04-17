#include <bits/stdc++.h>
using namespace std;

void merge(int *arr, int s, int e)
{

    int mid = (s + e) / 2;

    int len1 = mid - s + 1;
    int len2 = e - mid;

    int *left = new int[len1];
    int *right = new int[len2];

    int k = s;
    for (int i = 0; i < len1; i++)
    {
        left[i] = arr[k];
        k++;
    }

    k = mid + 1;
    for (int i = 0; i < len2; i++)
    {
        right[i] = arr[k];
        k++;
    }

    int leftindex = 0;
    int rightindex = 0;
    int mainarrayindex = s;

    while (leftindex < len1 and rightindex < len2)
    {
        if (left[leftindex] < right[rightindex])
        {
            arr[mainarrayindex++] = left[leftindex++];
        }
        else
        {
            arr[mainarrayindex++] = right[rightindex++];
        }
    }

    while (leftindex < len1)
    {
        arr[mainarrayindex++] = left[leftindex++];
    }

    while (rightindex < len2)
    {
        arr[mainarrayindex++] = right[rightindex++];
    }
}

void mergesort(int *arr, int s, int e)
{
    if (s >= e)
    {
        return;
    }

    int mid = (s + e) / 2;

    mergesort(arr, s, mid);
    mergesort(arr, mid + 1, e);

    merge(arr, s, e);
}

int main()
{
    int arr[] = {4, 8, 2, 7, 5, 2, 9, 1};
    int n = 8;
    int s = 0;
    int e = n - 1;

    mergesort(arr, s, e);

    for(auto x:arr)
    {
        cout<<x<<" ";
    }

    return 0;
}