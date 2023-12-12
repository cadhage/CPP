#include<bits/stdc++.h>
using namespace std;
void addEdge(vector<int> adj[],int u,int v){
	adj[u].push_back(v);
} 
void DFSUtil(vector<int> adj[],int V,bool* tc[],int s, int v) 
{ 
    // Mark reachability from s to t as true. 
    tc[s][v] = true; 
  
    // Find all the vertices reachable through v 
    for (auto i = adj[v].begin(); i != adj[v].end(); ++i) 
        if (tc[s][*i] == false) 
            DFSUtil(adj,V,tc,s, *i); 
} 
  
// The function to find transitive closure. It uses 
// recursive DFSUtil() 
void transitiveClosure(vector<int> adj[],int V,bool* tc[]) 
{ 
    // Call the recursive helper function to print DFS 
    // traversal starting from all vertices one by one 
    for (int i = 0; i < V; i++) 
        DFSUtil(adj,V,tc,i, i); // Every vertex is reachable from self. 
  
    for (int i=0; i<V; i++) 
    { 
        for (int j=0; j<V; j++) 
            cout << tc[i][j] << " "; 
        cout << endl; 
    } 
} 
int main(){
	int V=4;
	vector<int> adj[V];
	addEdge(adj,0,1);
	addEdge(adj,0,2);
	addEdge(adj,1,2);
	addEdge(adj,2,0);
	addEdge(adj,2,3);
	addEdge(adj,3,3);
	bool* tc[V]; 
for (int i=0; i<V; i++) 
{ 
        tc[i] = new bool[V]; 
        memset(tc[i], false, V*sizeof(bool)); 
}
	transitiveClosure(adj,V,tc);
	return 0;
}
