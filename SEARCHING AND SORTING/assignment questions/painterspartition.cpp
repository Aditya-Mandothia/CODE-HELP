#include <bits/stdc++.h>
using namespace std;

bool isPossibleSolution(int arr[],int n,int k,long long mid){

    long long timeSum = 0;
    int c=1;

    for(int i=0;i<n;i++)
    {
        if(arr[i]>mid)
        {
            return false;
        }

        if(arr[i] + timeSum > mid)
        {
            c++;
            timeSum = arr[i]; //division for k painters
            if(c>k)
            {
                return false;
            }
        }
        else
        {
            timeSum += arr[i];
        }
    }

    return true;

}

long long minTime(int arr[], int n, int k)
{
    long long start = 0;
    long long end = accumulate(arr,arr+n,0);

    long long ans =-1;

    while(start<=end)
    {
        int mid = start + (end - start)/2;
        if(isPossibleSolution(arr,n,k,mid))
        {
            ans = mid;
            end = mid-1;
        }
        else
        {
            start = mid+1;
        }
    }

    return ans;
}

int main()
{
    int arr[] = {5,10,30,20,15};
    int k=3;
    int n=5;

    cout<<minTime(arr,n,k);
    return 0;
}