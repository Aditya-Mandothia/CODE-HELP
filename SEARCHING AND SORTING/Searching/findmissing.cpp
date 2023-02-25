#include<bits/stdc++.h>
using namespace std;

int findMissing(vector<int>&arr)
{
    for(int i=0;i<arr.size();i++)
    {
        int index = abs(arr[i]); //-1,3,-4,-3,-5 index =4

        if(arr[index-1]>0)
        {
            arr[index-1]*=-1;
        }
    }

    for(int i=0;i<arr.size();i++)
    {
        if(arr[i]>0)
        {
            return i+1;
        }
    }
}

int main()
{
    vector<int>arr = {1,2,3,3,5};  //numbers from 1 to N+1 i.e 5
    cout<<findMissing(arr);

return 0;
}