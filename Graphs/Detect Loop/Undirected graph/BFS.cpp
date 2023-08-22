// GFG problem - https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<int>parent(V,0);
        queue<int>q;
        vector<bool>vis(V, false);
        for(int i=0;i<V;i++) {parent[i]=i;}
        for(int i=0;i<V;i++)
        {
            if(vis[i]==false)
            {
                q.push(i);
                vis[i] = true;
                while(!q.empty())
                {
                    int top = q.front();
                    q.pop();
                    for(int j=0;j<adj[top].size();j++)
                    {
                        if(parent[top]!=adj[top][j]&&parent[adj[top][j]]!=top)
                        {
                            if(vis[adj[top][j]]==false)
                            {
                                vis[adj[top][j]] = true;
                                parent[adj[top][j]] = top;
                                q.push(adj[top][j]);
                            }
                            else return true;
                        }
                    }
                }
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
