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
bool DFSUtil(vector<int> v[],bool b[],bool f[],int c,int d);
void DFS(vector<int> adj[],int x,int V){
	bool visited[V];
	bool rec[V];
	for(int i=0;i<V;i++){
		if(DFSUtil(adj,visited,rec,i,V))
				cout<<"Yes"<<"\n";
				return;
		}
	cout<<"No";
}
bool DFSUtil(vector<int> adj[],bool visited[],bool rec[],int i,int V){
	if(!visited[i]){
		visited[i]=true;
		rec[i]=true;
		for(int x:adj[i]){
			if(!visited[x]&& DFSUtil(adj,visited,rec,x,V))
			return true;
			else if(rec[x])
				return true;
		}
		
	}
	
	rec[i]=false;
	return false;
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
