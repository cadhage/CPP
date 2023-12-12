#include <bits/stdc++.h>
using namespace std;
int m=100;
void addEdge(vector<int> adj[],int src,int dest){
	adj[src].push_back(dest);
}
void DFSUtil(vector<int> adj[],int V,bool visited[],int i){
	visited[i]=true;
	cout<<i<<" ";
	for(auto it=adj[i].begin();it!=adj[i].end();it++){
		if(!visited[*it]){
			DFSUtil(adj,V,visited,*it);
		}
	}
}
void DFS(vector<int> adj[],int V,int i){
	bool visited[V];
	fill(visited,visited+V,false);
	DFSUtil(adj,V,visited,i);
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
	DFS(adj,V,0);
	return 0;
}
