#include<bits/stdc++.h>
using namespace std;

int main()
{

    int n;
    cout<<"Enter the no. of nodes: ";
    cin>>n;

    vector<vector<int>>adj(n,vector<int>(n,0));

    int e;
    cout<<"\nEnter the no. of edges: ";
    cin>>e;

    for(int i=1;i<=e;i++)
    {
        int u,v;
        cin>>u;
        cin>>v;

        adj[u][v]=1;

    }

    cout<<"\nPrinting the adjacency matrix: "<<endl;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<adj[i][j]<<" ";
        }

        cout<<endl;
    }

return 0;
}