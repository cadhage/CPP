#include <bits/stdc++.h>
using namespace std;
void addEdge(vector<int> adj[],int src,int dest){
	adj[src].push_back(dest);
}
void DFSUtil(vector<int> adj[],int V,bool visited[],int u,int d,int &pathCount){
	visited[u]=true;
	if(u==d)
		pathCount++;
	else{
		for(auto it=adj[u].begin();it!=adj[u].end();it++){
		if(!visited[*it]){
			DFSUtil(adj,V,visited,*it,d,pathCount);
		}
		}
	}
	visited[u]=false;
}
int DFS(vector<int> adj[],int u,int v,int V){
	bool visited[V];
	fill(visited,visited+V,false);
	int pathCount=0;
	DFSUtil(adj,V,visited,u,v,pathCount);
	return pathCount;
}
int main(){
	int n = 4; 
    vector <int> edges[4]; 
    addEdge(edges, 0, 1); 
    addEdge(edges, 0, 2); 
    addEdge(edges, 0, 3); 
    addEdge(edges, 2, 0); 
    addEdge(edges, 2, 1); 
    addEdge(edges, 1, 3); 
    int s = 2; 
    int d = 3;
	cout<<DFS(edges,s,d,n);
	return 0;
}
