#include<bits/stdc++.h>
using namespace std;

 int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int>visited(V,0);

        pq.push({0,0}); // no need of parent as we are not printing the nodes in the MST
        int sum = 0;

        while(!pq.empty())
        {
            auto it = pq.top();
            pq.pop();

            int node = it.second;
            int wt = it.first;

            if(visited[node] == 1) continue;

            visited[node]=1; //mark visited only when adding in sum
            sum += wt;

            for(auto it : adj[node])
            {
                int adjNode = it[0];
                int edgeWt = it[1];

                if(visited[adjNode]==0)
                {
                    pq.push({edgeWt,adjNode});
                }
            }


        }

        return sum;
    
    }