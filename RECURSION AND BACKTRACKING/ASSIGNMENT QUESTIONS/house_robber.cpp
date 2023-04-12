#include<bits/stdc++.h>
using namespace std;

int rob(vector<int> &arr, int i)
{
    //base case
    if(i>=arr.size())
    return 0;

    int ans1 = arr[i] + rob(arr,i+2);
    int ans2 = 0 + rob(arr,i+1);

    int final = max(ans1,ans2);

    return final;

}

int main()
{

    vector<int> arr = {2,1,1,2};
    int i=0;

    cout<<rob(arr,i);

return 0;
}