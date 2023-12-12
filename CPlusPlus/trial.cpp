#include <bits/stdc++.h>
using namespace std;
void addEdge(vector<int> adj[],int src,int dest){
	adj[src].push_back(dest);
}
void DFSUtil(vector<int> adj[],bool visited[],int V,int i){
	visited[i]=true;
//	cout<<i<<" ";
	for(auto it=adj[i].begin();it!=adj[i].end();it++){
		if(!visited[*it])
			DFSUtil(adj,visited,V,*it);
		}
}
int count(vector<int> adj[],int V){
	int res=0;
	bool visited[V];
	fill(visited,visited+V,false);
	int v=0;
	for(int i=0;i<V;i++)
		if(!visited[i]){
			DFSUtil(adj,visited,V,i);
			v=i;
		}
	fill(visited,visited+V,false);
	DFSUtil(adj,visited,V,v);
	for(int i=0;i<V;i++)
		if(!visited[i]){
			return -1;
		}
	return v;
}
int main(){
	int V=7;
	vector<int> adj[V];
	addEdge(adj,0,1);
	addEdge(adj,0,2);
	addEdge(adj,1,3);
	addEdge(adj,4,1);
	addEdge(adj,6,4);
	addEdge(adj,5,6);
	addEdge(adj,5,2);
	addEdge(adj,6,0);
	cout<<count(adj,V)<<" ";
	return 0;
}
