#include<bits/stdc++.h>
using namespace std;

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        vector<int>vis(V, false);
        int ans = 0;
        q.push({0,0});
        while(!q.empty())
        {
            int v = q.top().second;
            int w = q.top().first;
            q.pop();
            if(vis[v]==true)
            continue;
            vis[v] = true;
            ans+=w;
            for(auto a: adj[v])
            {
                if(vis[a[0]]==false)
                {
                    q.push({a[1], a[0]});
                }
            }
        }
        return ans;
    }
};


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}
