// GFG link  - https://www.geeksforgeeks.org/detect-cycle-in-a-graph/
#include <bits/stdc++.h>
using namespace std;


bool check(int V, vector<int>adj[],vector<bool>&visited,int i,vector<int>&mark){
    if(visited[i]==true)
    return true;
    mark[i]=1;
    visited[i]=true;
    for(int j=0;j<adj[i].size();j++){
        
        if(check(V,adj,visited,adj[i][j],mark))
        return true;
    }
    visited[i]=false;
    return false;
}
bool isCyclic(int V, vector<int> adj[])
{
    // Your code here
     vector<bool>visited(V,false);
     vector<int>mark(V,0);
     for(int i=0;i<V;i++){
         if(mark[i]==0)
         if(check(V,adj,visited,i,mark))
         return true;
     }
     return false;
}


int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int v, e;
	    cin >> v >> e;
	    
	    vector<int> adj[v];
	    
	    for(int i =0;i<e;i++){
	        int u, v;
	        cin >> u >> v;
	        adj[u].push_back(v);
	    }
	    
	    cout << isCyclic(v, adj) << endl;
	    
	}
	
	return 0;
}  
