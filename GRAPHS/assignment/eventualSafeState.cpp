//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int check(vector<int> adj[], int src, unordered_map<int, bool> &visited, unordered_map<int, bool> &dfsVisited, int safeNodes[])
    {

        visited[src] = true;
        dfsVisited[src] = true;
        safeNodes[src] = 0;

        for (auto nbr : adj[src])
        {
            if (!visited[nbr])
            {
                bool aageKaAns = check(adj, nbr, visited, dfsVisited, safeNodes);
                if (aageKaAns == true)
                    return true;
            }

            if (visited[nbr] == true and dfsVisited[nbr] == true)
            {
                return true;
            }
        }

        dfsVisited[src] = false;
        safeNodes[src] = 1;
        return false;
    }

    vector<int> eventualSafeNodes(int V, vector<int> adj[])
    {
        // code here
        vector<int> ans;
        unordered_map<int, bool> visited, dfsVisited;
        int safeNodes[V] = {0};

        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                check(adj, i, visited, dfsVisited, safeNodes);
            }
        }

        for (int i = 0; i < V; i++)
        {
            if (safeNodes[i])
                ans.push_back(i);
        }

        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes)
        {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends