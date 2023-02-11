#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> a = {1, 1, 0, 1, 1, 0, 0, 0, 1};

    cout << "before sorting 0's and 1's : "<<endl;
    for (auto x : a)
    {
        cout << x << " ";
    }

    int i=0;
    int j=a.size()-1;

    while(i<j)
    {
        if(a[i] == 1)
        {
            if(a[j] == 0)
            {
                swap(a[i],a[j]);
            }
            else{
                j--;
            }
        }
        else{
            i++;
        }
    }

    cout << "\nafter sorting 0's and 1's : "<<endl;
    for( auto x:a)
    {
        cout<<x<<" ";
    }
    return 0;
}