// GFG link  - https://www.geeksforgeeks.org/detect-cycle-in-a-graph/
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool helper(vector<int>adj[], int v, vector<pair<bool, bool>>&vis)
    {
        if(vis[v].second==true)
        return true;
        vis[v].first = true;
        vis[v].second = true;
        for(int i=0;i<adj[v].size();i++)
        {
            if(vis[adj[v][i]].first==false)
            {
                if(helper(adj, adj[v][i], vis))
                return true;
            }
            else if(vis[adj[v][i]].second==true)
            return true;
        }
        
        vis[v].second = false;
        vis[v].first = true;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<pair<bool, bool>>vis(V, {false, false});
        return helper(adj, 0, vis);
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

