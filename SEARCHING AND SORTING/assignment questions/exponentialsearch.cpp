#include<bits/stdc++.h>
using namespace std;

// subpart mein bs lagana is exponential bs

// applications :
// efficient when element present at lesser index
// unbounded bs uses this (sort the infinte array)

int bs(int a[],int start,int end,int x)
{
    int mid = (start+end)/2;

    while(start<=end)
    {
        if(a[mid]==x)
        return mid;

        else if(a[mid]>x)
        {
            end = mid-1;
        }
        else{
            start = mid+1;
        }

        mid = (start+end)/2;
    }

    return -1;
}


int expSearch(int a[],int n,int x)
{
    if(a[0]==x)
    {
        return 0;
    }

    int i=1;

    while(i<n and a[i]<=x)
    {
        i=i*2;
    }

    return bs(a,i/2,min(i,n-1),x);
}

int main()
{

    int a[] = {3,4,5,11,13,17,18,56,92}; //arrays needs to be sorted cause ultimately we want to apply bs
    int x = 13;
    int n = sizeof(a)/sizeof(int);

    int ans = expSearch(a,n,x);
    cout<<ans;

return 0;
}