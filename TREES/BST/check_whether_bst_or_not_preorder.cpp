#include <bits/stdc++.h>
using namespace std;

void check(int &i,int min, int max, vector<int>&a)
{
    if(i>=a.size())
    {
        return;
    }

    if(a[i] > min and a[i] < max)
    {   
        int rootdata = a[i++];
        check(i,min,rootdata,a);
        check(i,rootdata,max,a);
    }
}

int helper(vector<int>&a)
{
    int i=0;
    int min=INT_MIN;
    int max = INT_MAX;

    check(i,min,max,a);

    return i==a.size();
}

int main()
{

    vector<int> a = {10, 8, 7, 9, 20, 15, 21};
    cout<<helper(a);
    
}