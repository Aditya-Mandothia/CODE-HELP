#include <bits/stdc++.h>
using namespace std;

class Solution

{
public:
    void helper(int V, vector<int> adj[], unordered_map<int, bool> &visited, stack<int> &s)
    {
        visited[V] = true;

        for (auto nbr : adj[V])
        {
            if (!visited[nbr])
                helper(nbr, adj, visited, s);
        }

        s.push(V);
    }

    // Function to return list containing vertices in Topological order.
    vector<int> topoSort(int V, vector<int> adj[])
    {
        // code here
        unordered_map<int, bool> visited;
        stack<int> s;
        vector<int> result;

        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
                helper(i, adj, visited, s); // considering all disconnected graphs
        }

        while (!s.empty())
        {
            int ans = s.top();
            result.push_back(ans);
            s.pop();
        }

        return result;
    }
};

//{ Driver Code Starts.

/*  Function to check if elements returned by user
 *   contains the elements in topological sorted form
 *   V: number of vertices
 *   *res: array containing elements in topological sorted form
 *   adj[]: graph input
 */
int check(int V, vector<int> &res, vector<int> adj[])
{

    if (V != res.size())
        return 0;

    vector<int> map(V, -1);
    for (int i = 0; i < V; i++)
    {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++)
    {
        for (int v : adj[i])
        {
            if (map[i] > map[v])
                return 0;
        }
    }
    return 1;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++)
        {
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }

    return 0;
}
// } Driver Code En