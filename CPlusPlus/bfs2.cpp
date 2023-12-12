#include<bits/stdc++.h>
using namespace std;
void addEdge(vector<int> adj[],int a,int b){
	adj[a].push_back(b);
}
void printAdj(vector<int> adj[],int v){
	for(int i=0;i<v;i++){
		cout<<i<<" ";
		for(int x:adj[i]){
			cout<<x<<" ";
		}
		cout<<"\n";
	}
}
void DFSUtil(vector<int> v[],bool b[],int c,int d);
void DFS(vector<int> adj[],int i,int V){
	bool visited[V];
	DFSUtil(adj,visited,i,V);
}
void DFSUtil(vector<int> adj[],bool visited[],int i,int V){
	visited[i]=true;
	cout<<i<<" ";
	for(int x:adj[i]){
		if(!visited[x])
			DFSUtil(adj,visited,x,V);
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
	printAdj(adj,V);
	bool visited[V];
	DFS(adj,0,V);
	return 0;
}
