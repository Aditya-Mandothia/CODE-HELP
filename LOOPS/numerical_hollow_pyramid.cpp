#include <bits/stdc++.h>
using namespace std;

int main()
{   
    int n;
    cin>>n;

    for(int i=0;i<n;i++)
    {
        for(int j=n-1-i;j>0;j--)
        {
            cout<<" ";
        }

        int start=1;

        // print full pyramid of numbers
        for(int j=0;j<=2*i;j++)
        {
            if(i==0 ||i==n-1)
            {
                if(j%2==0)
                {
                    cout<<start;
                    start++;
                }
                else{
                    cout<<" ";
                }
            }
            else{
                if(j==0)
                {
                    cout<<1;
                }
                else if(j==2*i)
                {
                    cout<<i+1;
                }
                else{
                    cout<<" ";
                }
            }


        }

        cout<<endl;


    }

    return 0;
}