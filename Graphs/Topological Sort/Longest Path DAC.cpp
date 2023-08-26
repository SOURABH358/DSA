// https://www.geeksforgeeks.org/find-longest-path-directed-acyclic-graph/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
//Function to return list containing vertices in Topological order. 
vector<int> longestPath(int v, vector<vector<int>>adj[], int src)
{
    vector<int>indeg(v,0);
    vector<int>dis(v, INT_MIN);
    dis[src] = 0;
    for(int i=0=;i<v;i++)
    {
        for(auto j: adj[i])
        {
            indeg[j[0]]++;
        }
    }
    queue<int>q;
    q.push(src);
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(auto v: adj[u])
        {
            if(dis[u]!=INT_MIN&&dis[v[0]]<dis[u]+v[1])
            dis[v[0]] = dis[u] + v[1];
            if(--indeg[v[0]]==0)
            {
                q.push(v);
            }
        }
    }
    return dis;
}
	
};

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v, t;

        vector<vector<int>> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v >> t;
            adj[u].push_back({v,t});
        }
        
        Solution obj;
        vector <int> res = obj.longestPath(N, adj, 0);

    }
    
    return 0;
}
// Complexity Analysis: 
 
// Time Complexity: O(V+E). 
// The outer for loop will be executed V number of times and the inner for loop will be executed E number of times.
// Auxiliary Space: O(V). 
// The queue needs to store all the vertices of the graph. So the space required is O(V)
