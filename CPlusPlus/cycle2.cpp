#include<bits/stdc++.h>
using namespace std;
void addEdge(vector<int> adj[],int a,int b){
	adj[a].push_back(b);
	adj[b].push_back(a);
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
bool DFSUtil(vector<int> v[],bool b[],bool f[],int c,int d,int p);
void DFS(vector<int> adj[],int x,int V){
	bool visited[V];
	bool rec[V];
	for(int i=0;i<V;i++){
		if(!visited[i]&&DFSUtil(adj,visited,rec,i,V,-1))
				cout<<"Yes"<<"\n";
				return;
		}
	cout<<"No";
}
bool DFSUtil(vector<int> adj[],bool visited[],bool rec[],int i,int V,int present){
//	if(!visited[i]){
		visited[i]=true;
		rec[i]=true;
		for(int x:adj[i]){
			if(!visited[x]&& DFSUtil(adj,visited,rec,x,V,i))
				return true;
			else if(x!=present)
				return true;
		}
		
//	}
	
//	rec[i]=false;
	return false;
}
int main(){
	int V=5;
	vector<int> adj[V];
	addEdge(adj,0,1);
	addEdge(adj,0,2);
	addEdge(adj,2,0);
	addEdge(adj,0,3);
	addEdge(adj,3,4);
	printAdj(adj,V);
	bool visited[V];
	DFS(adj,0,V);
	return 0;
}
