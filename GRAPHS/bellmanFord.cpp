#include <bits/stdc++.h>
using namespace std;

class Graph
{
public:
    unordered_map<int, list<pair<int, int>>> adjList;

    void addEdge(int u, int v, int wt, bool direction)
    {
        // 0 means directed, 1 means undirected
        adjList[u].push_back({v, wt});

        if (direction == 1)
        {
            adjList[v].push_back({u, wt});
        }
    }

    void printAdjList()
    {
        for (auto i : adjList)
        {
            cout << i.first << "-> ";

            for (auto j : i.second)
            {
                cout << "( " << j.first << "," << j.second << " )";
            }

            cout << endl;
        }
    }

    void bellmanFord(int src, int n) // src= source node, n= number of nodes
    {
        vector<int> dist(n, INT_MAX); // this vector will have the shortest distance from source node to ith nodes
        dist[src] = 0;

        for (int i = 0; i < n - 1; i++)
        {
            // do relaxation

            for (auto t : adjList)
            {
                for (auto nbr : t.second)
                {
                    int u = t.first;
                    int v = nbr.first;
                    int wt = nbr.second;

                    if (dist[u] != INT_MAX and dist[u] + wt < dist[v])
                    {
                        dist[v] = dist[u] + wt;
                    }
                }
            }
        }

        for (auto x : dist)
        {
            cout << x << " ";
        }
    }
};

int main()
{
    Graph g;

    // g.addEdge(0,1,1,1);
    // g.addEdge(1,2,1,1);
    // g.addEdge(2,3,1,1);

    // g.addEdge(3,4,1,1);
    // g.addEdge(0,5,1,1);
    // g.addEdge(5,4,1,1);

    // g.addEdge(0,6,1,1);
    // g.addEdge(6,7,1,1);
    // g.addEdge(7,8,1,1);
    // g.addEdge(8,4,1,1);

    // g.printAdjList();
    // g.shortestPath(0,4);

    g.addEdge(0, 1, -1, 0);
    g.addEdge(0, 2, 4, 0);
    g.addEdge(1, 2, 3, 0);
    g.addEdge(1, 3, 2, 0);
    g.addEdge(1, 4, 2, 0);
    g.addEdge(3, 1, 1, 0);
    g.addEdge(3, 2, 5, 0);
    g.addEdge(4, 3, -3, 0);

    g.bellmanFord(0, 5);

    return 0;
}