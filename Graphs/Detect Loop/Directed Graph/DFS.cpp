// GFG link  - https://www.geeksforgeeks.org/detect-cycle-in-a-graph/
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool helper(vector<int>adj[], int v, vector<bool>&vis, vector<bool>&path)
    {
        if(vis[v]==false)
        {
            vis[v] = true;
            path[v] = true;
            for(int i=0;i<adj[v].size();i++)
            {
                if(vis[adj[v][i]]==false)
                {
                    if(helper(adj, adj[v][i], vis, path))
                    return true;
                }
                else if(path[adj[v][i]]==true)
                return true;
            }
        }
        
        path[v] = false;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<bool>vis(V, false);
        vector<bool>path(V, false);
        for (int i = 0; i < V; i++)
        if (!vis[i]
            && helper(adj, i, vis, path))
            return true;
        return false;
    }
};

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}
