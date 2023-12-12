#include<bits/stdc++.h>
using namespace std;
# define INF 0x3f3f3f3f 
typedef pair<int, int> iPair;
void addEdges(vector<pair<int,int>> adj[],int u,int v,int weight){
	adj[u].push_back(make_pair(v,weight));
	adj[v].push_back(make_pair(u,weight));
}
void printGraph(vector<pair<int,int>> adj[],int V){
	int v,w;
	for(int i=0;i<V;i++){
		for(auto it=adj[i].begin();it<adj[i].end();it++){
			v=it->first;
			w=it->second;
			cout<<v<<" "<<w<<endl;
		}
		cout<<endl;
	}
}
int main(){
	int V=9;
	vector<pair<int ,int>> adj[V];
	addEdges(adj,0,1,4);
	addEdges(adj,0,7,8);
	addEdges(adj,1,2,8);
	addEdges(adj,1,7,11);
	addEdges(adj,2,3,7);
	addEdges(adj,2,8,2);
	addEdges(adj,2,5,4);
	addEdges(adj,3,4,9);
	addEdges(adj,3,5,14);
	addEdges(adj,4,5,10);
	addEdges(adj,5,6,10);
	addEdges(adj,6,8,6);
	addEdges(adj,6,8,7);
	addEdges(adj,7,8,7);
	shortest_path(0,adj,V);
	cout<<endl;
	prims(adj,V);
	return 0;
}
