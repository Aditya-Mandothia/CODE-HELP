#include<bits/stdc++.h>
using namespace std;

int count_ways(int n,int k)
{
    if(n==1)
    {
        return k;
    }

    if(n==2)
    {
        return k*k;
    }

    int ans =  (count_ways(n-1,k) + count_ways(n-2,k))*(k-1); 
    return ans;
}

int main()
{
    int n=4;
    int k=3;

    cout<<count_ways(n,k);

return 0;
}