// https://www.geeksforgeeks.org/find-longest-path-directed-acyclic-graph/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
vector<int> longestPath(int v, vector<int>adj[], int src)
{
    vector<int>indeg(v,0);
    vector<int>dis(v, INT_MIN);
    dis[src] = 0;
    for(int i=0=;i<v;i++)
    {
        for(auto j: adj[i])
        {
            indeg[j]++;
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
            if(dis[u]!=INT_MIN&&dis[v]<dis[u]+adj[u][v])
            dis[v] = dis[u] + adjv[u][v];
            if(--indeg[v]==0)
            {
                q.push(v);
            }
        }
    }
    return dis;
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
        vector <int> res = obj.longestPath(N, adj, 0);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}
// Time Complexity: Time complexity of topological sorting is O(V+E). After finding topological order, the algorithm process all vertices and for every vertex, it runs a loop for all adjacent vertices. 
// Total adjacent vertices in a graph is O(E). So the inner loop runs O(V+E) times. Therefore, overall time complexity of this algorithm is O(V+E).

// Space complexity : O(V + E), where V is the number of vertices and E is the number of edges in the graph. 
