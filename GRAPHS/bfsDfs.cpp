#include <bits/stdc++.h>
using namespace std;

template <typename T>

class Graph
{
public:
    unordered_map<T, list<T>> adjList;

    void addEdge(T u, T v, bool direction)
    {
        adjList[u].push_back(v);

        if (direction == 0)
        {
            adjList[v].push_back(u);
        }
    }

    void printAdjList()
    {
        for (auto node : adjList)
        {
            cout << node.first << "->> ";

            for (auto neighbour : node.second)
            {
                cout << neighbour << ",";
            }

            cout << endl;
        }
    }

    void bfs(int src)
    {
        queue<int> q;
        unordered_map<int, bool> visited;

        q.push(src);
        visited[src] = true;

        while (!q.empty())
        {
            int frontNode = q.front();
            q.pop();
            cout << frontNode << ", ";

            for (auto neighbours : adjList[frontNode])
            {
                if (!visited[neighbours])
                {
                    q.push(neighbours);
                    visited[neighbours] = true;
                }
            }
        }
    }

    void dfs(int src, unordered_map<int, bool> &visited)
    {
        cout << src << " ";
        visited[src] = true;

        for (auto neighbour : adjList[src])
        {
            if (!visited[neighbour])
                dfs(neighbour, visited);
        }
    }
};

int main()

{
    Graph<int> g;

    g.addEdge(0, 1, 1); // 1 means directed
    g.addEdge(1, 2, 1);
    g.addEdge(0, 2, 1);

    cout << endl;
    int n = 3;

    unordered_map<int, bool> visited2;

    // g.printAdjList();
    for (int i = 0; i < n; i++)
    {
        if (!visited2[i])
        {
            g.dfs(i, visited2);
        }
    }
    // g.bfs(0);

    return 0;
}