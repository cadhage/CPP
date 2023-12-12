#include <bits/stdc++.h>
using namespace std;
void addEdge(vector<int> adj[],int src,int dest){
	adj[src].push_back(dest);
}
void DFSUtil(vector<int> adj[],bool visited[],int V,int i){
	visited[i]=true;
	//cout<<i<<" ";
	for(auto it=adj[i].begin();it!=adj[i].end();it++){
		if(!visited[*it])
			DFSUtil(adj,visited,V,*it);
		}
}
void count(vector<int> adj[],int V){
	int res=0;
	bool visited[V];
	fill(visited,visited+V,false);
	for(int i=0;i<V;i++){
		if(!visited[i]){
			DFSUtil(adj,visited,V,i);
			res++;
			}
	}
	cout<<res<<endl;
}
int main(){
	int V=5;
	vector<int> adj[V];
	addEdge(adj,0,1);
	addEdge(adj,0,2);
	addEdge(adj,3,4);
	count(adj,V);
	return 0;
}
