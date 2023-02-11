#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int>a;

    a.push_back(5);

    // a[0] exists
    a.push_back(10);

    cin>>a[1];

    for(auto x:a)
    {
        cout<<x<<" ";
    }
    // a.push_back(15);

    //4,3

    // a.pop_back();

    //4,2
    

    // int i=0;

    // for(;i<5;i++)
    // {
    //     cin>>a[i];
    // }

    // i++;

    // cin>>a[i];

    

    // for(int x:a)
    // {
    //     cout<<x<<" ";
    // }

    // cout<<endl;

    cout<<endl<<a.capacity()<<endl;
    cout<<a.size();

    



    return 0;
}