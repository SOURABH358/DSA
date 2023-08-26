//https://www.geeksforgeeks.org/topological-sorting-indegree-based-solution/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	   vector<int>res;
	   vector<int>indeg(V, 0);
	   queue<int>q;
	    for(int i=0;i<V;i++)
	    {
	        for(auto b: adj[i])
	        {
	            indeg[b]++;
	        }
	    }
	    for(int i=0;i<V;i++)
	    {
	        if(indeg[i]==0)
	        q.push(i);
	    }
	    while(!q.empty())
	    {
	        int t = q.front();
	        q.pop();
	        res.push_back(t);
	        for(auto a: adj[t])
	        {
	            indeg[a]--;
	            if(indeg[a]==0) q.push(a);
	        }
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
// }
// Complexity Analysis: 
 
// Time Complexity: O(V+E). 
// The outer for loop will be executed V number of times and the inner for loop will be executed E number of times.
// Auxiliary Space: O(V). 
// The queue needs to store all the vertices of the graph. So the space required is O(V)
