#include <bits/stdc++.h>
using namespace std;

vector<int> findKclosest(vector<int> arr, int k, int x)
{

    // sort(arr.begin(),arr.end());

    int l = 0;
    int h = arr.size() - 1;

    while (h - l >= k)
    {
        if (x - arr[l] > arr[h] - x)
        {
            l++;
        }
        else
        {
            h--;
        }
    }

    vector<int> ans;

    for (int i = l; i <= h; i++)
    {
        ans.push_back(arr[i]);
    }

    return ans;
}


int lowerBound(vector<int>arr,int x)
{
    int start = 0;
    int end = arr.size()-1;

    int ans =end;

    while(start<=end)
    {
        int mid = (start+end)/2;
        if(arr[mid]>=x)
        {
            ans = mid;
            end = mid-1;
        }
        else if(arr[mid]<x)
        {
            start = mid+1;
        }
        else {
            end = mid-1;
        }
    }

    return ans;
}

vector<int> findKclosest2(vector<int> arr, int k, int x)
{
    int h = lowerBound(arr, x);
    int l = h - 1;

    while(k--)
    {   
        if(l<0)
        {
            h++;
        }
        else if(h>arr.size())
        {
            l--;
        }


        if(x-arr[l] > arr[h]-x)
        {
            h++;
        }
        else{
            l--;
        }
    }

    vector<int> ans;

    for (int i = l+1; i < h; i++)
    {
        ans.push_back(arr[i]);
    }

    return ans;



}

int main()
{

    vector<int> arr = {1, 2, 3, 4, 5};
    int k = 4;
    int x = 3;

    vector<int> ans = findKclosest2(arr, k, x);

    for (auto x : ans)
    {
        cout << x << " ";
    }

    return 0;
}