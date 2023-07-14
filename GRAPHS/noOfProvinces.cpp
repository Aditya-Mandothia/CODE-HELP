#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void dfs(int src, vector<vector<int>> &adjList, vector<int> &visited)
    {

        visited[src] = 1;

        for (auto nbr : adjList[src])
        {
            if (visited[nbr] == 0)
                dfs(nbr, adjList, visited);
        }
    }

    int findCircleNum(vector<vector<int>> &isConnected)
    {

        int n = isConnected.size();

        vector<vector<int>> adjList(n, vector<int>(n, 0));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i != j and isConnected[i][j] == 1)
                {
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        }

        vector<int> visited(n, 0);
        int count = 0;

        for (int i = 0; i < n; i++)
        {
            if (visited[i] == 0)
            {
                count++;
                dfs(i, adjList, visited);
            }
        }

        return count;
    }
};