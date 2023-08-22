#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<int>indeg(V, 0);
        queue<int>q;
        int c= 0;
        for(int i=0;i<V;i++)
        {
            for(auto u: adj[i])
            indeg[u]++;
        }
        for(int i=0;i<V;i++)
        {
            if(indeg[i]==0)
            q.push(i);
        }
        while(!q.empty())
        {
            int top = q.front();
            q.pop();
            c++;
            for(auto a: adj[top])
            {
                if(--indeg[a]==0)
                {
                    q.push(a);
                }
            }
        }
        return c!=V;
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

