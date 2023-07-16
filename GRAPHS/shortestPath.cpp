#include<bits/stdc++.h>
using namespace std;

class Graph{
    public:
    unordered_map<int,list<pair<int,int>>> adjList;

    void addEdge(int u, int v, int wt, bool direction )
    {   
        //0 means directed, 1 means undirected
        adjList[u].push_back({v,wt});

        if(direction==1)
        {
            adjList[v].push_back({u,wt});
        }
    }

    void printAdjList(){
        for(auto i : adjList)
        {
            cout<<i.first<<"-> ";

            for(auto j : i.second)
            {
                cout<<"( "<<j.first<<","<<j.second<<" )";
            }

            cout<<endl;
        }
    }

    void shortestPath(int src, int dest)
    {
        queue<int>q;
        unordered_map<int,bool>visited;
        unordered_map<int,int>parent;

        q.push(src);
        visited[src]=1;
        parent[src]=-1;

        while(!q.empty())
        {
            int fnode = q.front();
            q.pop();

            for(auto nbr : adjList[fnode])
            {
                if(!visited[nbr.first])
                {
                    q.push(nbr.first);
                    visited[nbr.first]=1;
                    parent[nbr.first]=fnode;
                }
            }
        }

        vector<int>ans;

        int node = dest;

        while(node != -1)
        {
            ans.push_back(node);
            node = parent[node];
        }

        reverse(ans.begin(),ans.end());

        for(auto x : ans)
        {
            cout<<"->"<<x;
        }
        
    }
};

int main()
{
    Graph g;

    g.addEdge(0,1,1,1);
    g.addEdge(1,2,1,1);
    g.addEdge(2,3,1,1);


    g.addEdge(3,4,1,1);
    g.addEdge(0,5,1,1);
    g.addEdge(5,4,1,1);

    
    g.addEdge(0,6,1,1);
    g.addEdge(6,7,1,1);
    g.addEdge(7,8,1,1);   
    g.addEdge(8,4,1,1);

    // g.printAdjList();
    g.shortestPath(0,4);
    


return 0;
}