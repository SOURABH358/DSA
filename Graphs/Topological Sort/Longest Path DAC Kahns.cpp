#include <bits/stdc++.h>
using namespace std;

class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	void dfs(vector<vector<int>>adj[], int i, stack<int>&s, vector<bool>&vis)
	{
	    if(vis[i])
	    return ;
	    vis[i] = true;
	    for(auto j: adj[i])
	    {
	        if(!vis[j[0]])
	        {
	            dfs(adj, j[0], s, vis);
	        }
	    }
	    s.push(i);
	}
	vector<int> longestPath(int V, vector<vector<int>> adj[], int src) 
	{
	    vector<bool>vis(V, false);
	    vector<int>dis(V, INT_MIN);
	    dis[src] = 0;
	    stack<int>s;
	    // get element in topological sort
	    for(int i=0;i<V;i++)
	    {
	        if(!vis[i])
	        {
	            dfs(adj, i, s, vis);
	        }
	    }
	    
    	while(!s.empty())
    	{
    	    int u = s.top();
    	    s.pop();
    	    if(dis[u]!=INT_MIN)
    	    {
    	        for(auto v: adj[u])
    	        {
    	            if(dis[v]<dis[u]+ v[1])
    	            dis[v] = dis[u] + v[1];
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
        int u, v,t;

        vector<vector<int>> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v >> t;
            adj[u].push_back({v,t});
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj,0);

    }
    
    return 0;
}
// Time Complexity: Time complexity of topological sorting is O(V+E). After finding topological order, the algorithm process all vertices and for every vertex, it runs a loop for all adjacent vertices. 
// Total adjacent vertices in a graph is O(E). So the inner loop runs O(V+E) times. Therefore, overall time complexity of this algorithm is O(V+E).

// Space complexity : O(V + E), where V is the number of vertices and E is the number of edges in the graph. 
