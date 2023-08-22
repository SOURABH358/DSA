// GFG link https://www.geeksforgeeks.org/detect-cycle-undirected-graph/
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
  bool helper(int v, vector<int>adj[], vector<bool>& vis, int parent)
  {
      vis[v] = true;
      for(int i=0;i<adj[v].size();i++)
      {
          if(!vis[adj[v][i]])
          {
              if(helper(adj[v][i], adj, vis, v))
              return true;
          }
          else if(adj[v][i]!=parent)
          return true;
      }
      return false;
  }
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        vector<bool>vis(V, false);
        for(int i=0;i<V;i++)
        {
            if(vis[i] == false)
            {
                if(helper(i, adj, vis, -1))
                return true;
            }
        }
        return false;
    }
};

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
