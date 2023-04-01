#include <bits/stdc++.h>
using namespace std;

bool checksort(vector<int>&arr, int n, int i)
{
    //base case
    if(i==n-1)
    {
        return true;
    }

    //ek case solve karo
    if(arr[i+1]<arr[i])
    {
        return false;
    }

    //baki recursion sambhal lega
    checksort(arr,n,i+1);

}

int main()
{

    vector<int> arr = {10, 20, 30, 40, 50};
    int n = arr.size();
    int i = 0;

    if (checksort(arr, n, i))
    {
        cout << "sorted" << endl;
    }
    else
    {
        cout << "Not sorted!" << endl;
    }

    return 0;
}