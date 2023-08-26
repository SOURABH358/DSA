// https://www.geeksforgeeks.org/topological-sorting/
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	void dfs(vector<int>adj[], int i, stack<int>&s, vector<bool>&vis)
	{
	    if(vis[i])
	    return ;
	    vis[i] = true;
	    for(auto j: adj[i])
	    {
	        if(!vis[j])
	        {
	            dfs(adj, j, s, vis);
	        }
	    }
	    s.push(i);
	}
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<bool>vis(V, false);
	    stack<int>s;
	    // get element in topological sort
	    for(int i=0;i<V;i++)
	    {
	        if(!vis[i])
	        {
	            dfs(adj, i, s, vis);
	        }
	    }
	    vector<int>res;
    	while(!s.empty())
    	{
    	    res.push_back(s.top());
    	    s.pop();
    	}
    	return res;
	}
	
};

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}
// Complexity Analysis: 
 
// Time Complexity: O(V+E). 
// The outer for loop will be executed V number of times and the inner for loop will be executed E number of times.
// Auxiliary Space: O(V). 
// The queue needs to store all the vertices of the graph. So the space required is O(V)
