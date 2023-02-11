#include <bits/stdc++.h>
using namespace std;

int main()
{   
    vector<int> a ={1,1,2,2,1,2,3,5,5,5,6,6,6}; //randawa pakad liya
    // int freq[7] = {0};

    int ans=0;

    for(int i=0;i<a.size();i++)
    {
        ans = ans ^ a[i];
    }

    cout<<ans;

    // int f = 1^2;
    // cout<<f;

    // 0,2,1,2,0,2,2

    // for(int i=0;i<a.size()-1;i++)
    // {
    //     freq[a[i]]++;
    // } //o(n)

    // for(int i=0;i<7;i++)
    // {
    //     if(freq[i]==1)
    //     {
    //         cout<<i;
    //         break;
    //     }
        
       
    // } //o(n)







    return 0;
}