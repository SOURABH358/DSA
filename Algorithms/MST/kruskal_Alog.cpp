// GFG link - https://www.geeksforgeeks.org/kruskals-minimum-spanning-tree-algorithm-greedy-algo-2/
#include<bits/stdc++.h>
using namespace std;

class Edge{
    public: 
    int w;
    int u;
    int v;
    Edge(int p, int q, int r)
    {
        w = p;
        u = q;
        v = r;
    }
};
class DisjointSet{
    public:
    int* parent;
    int* rank;
    DisjointSet(int V)
    {
        parent = new int[V];
        rank = new int[V];
        for(int i=0;i<V;i++)
        {
            parent[i] = -1;
            rank[i] = 0;
        }
    }
    int find(int x)
    {
        if(parent[x]==-1)
        {
            return x;
            
        }
        return parent [x] = find(parent[x]);;
    }
    void Union(int x, int y)
    {
        int xparent = find(x);
        int yparent = find(y);
        if(xparent != yparent)  //checking loops in cycle
        {
            if(rank[xparent]<rank[yparent])
            {
                parent[xparent] = yparent;
            }
            else if(rank[yparent]<rank[xparent])
            {
                parent[yparent] = xparent;
            }
            else{
                parent[yparent] = xparent;
                rank[xparent]++;
            }
        }
    }
};
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<vector<int>>EdgeList;
        for(int i=0;i<V;i++)
        {
            for(auto a: adj[i])
            {
                int w = a[1];
                int v= a[0];
                int u = i;
                EdgeList.push_back({w, u, v});
            }
        }
        sort(EdgeList.begin(), EdgeList.end());
        DisjointSet s(V);
        int ans = 0;
        for(auto a: EdgeList)
        {
            int w = a[0];
            int u = a[1];
            int v = a[2];
            if(s.find(u)!=s.find(v))
            {
                s.Union(u, v);
                ans+=w;
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
