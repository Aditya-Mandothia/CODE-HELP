#include <bits/stdc++.h>
using namespace std;

int firstR(vector<int> &arr)
{   
    //using hashing
    int table[6]={0};

    for (int i = 0; i < arr.size(); i++)
    {
        table[arr[i]]++;
    }

    for (int i = 0; i < arr.size(); i++)
    {
        if (table[arr[i]] > 1)
        {
            return arr[i];
            
        }
    }
}

int main()
{
    vector<int> arr = {1, 2, 3, 2, 5, 6, 5};
    cout<<firstR(arr);

    return 0;
}