#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

class Graph
{
public:
    // sadharan sa graph
    unordered_map<int, list<int>> adjList;

    void addEdge(int u, int v, bool direction)
    {
        // 0 means directed, 1 means undirected
        adjList[u].push_back(v);

        if (direction == 1)
        {
            adjList[v].push_back(u); // undirected hogi toh dono taraf lagao.
        }
    }

    void dfs1(int src, stack<int> &s, unordered_map<int, bool> &vis)
    {
        vis[src] = true;

        for (auto nbr : adjList[src])
        {
            if (!vis[nbr])
            {
                dfs1(nbr, s, vis);
            }
        }

        s.push(src);
    }

    void dfs2(int src, unordered_map<int, bool> &vis, unordered_map<int, list<int>> &adj)
    {
        vis[src] = true;
        cout<<src<<", ";

        for (auto nbr : adj[src])
        {
            if (!vis[nbr])
            {
                dfs2(nbr, vis, adj);
            }
        }
    }

    int countSCC(int n)
    {
        stack<int> s; // to store topological order
        unordered_map<int, bool> visited;

        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                dfs1(i, s, visited);
            }
        }

        // reversal of edges

        unordered_map<int, list<int>> adjNew; // for storing the reversed edges of SCC

        for (auto t : adjList)
        {
            for (auto nbr : t.second)
            {
                int u = t.first;
                int v = nbr;

                adjNew[v].push_back(u);
            }
        }

        // traversal that we stored in stack (topo ordering)
        int count = 0;
        unordered_map<int, bool> visited2;

        while (!s.empty())
        {
            int node = s.top();
            s.pop();

            if (!visited2[node])
            {   
                cout<<"Printing "<<count + 1<<" th SCC : ";
                dfs2(node, visited2, adjNew);
                cout<<endl;
                count++;
            }
            
        }

        return count;
    }
};

int main()
{
    Graph g;
    g.addEdge(0, 1, 0);
    g.addEdge(1, 2, 0);
    g.addEdge(2, 3, 0);
    g.addEdge(3, 0, 0);
    g.addEdge(2, 4, 0);
    g.addEdge(4, 5, 0);
    g.addEdge(5, 6, 0);
    g.addEdge(6, 4, 0);
    g.addEdge(6, 7, 0);

    cout <<"Number of SCC are : "<<g.countSCC(8);

    // first step is to create a stack so that you can store the topological sorted order
    // then reverse the graph edges to create seperation
    // itterate through stack and find the number of components

    return 0;
}