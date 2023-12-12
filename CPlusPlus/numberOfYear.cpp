#include <bits/stdc++.h>
using namespace std;
void addEdge(vector<int> adj[],int src,int dest){
	adj[src].push_back(dest);
}
int BFS(vector<int> adj[],int u,int v,int V){
	bool visited[V];
	int dist[V];
	fill(dist,dist+V,0);
	fill(visited,visited+V,false);
	visited[u]=true;
	dist[u]=0;
	list<int> q;
	q.push_back(u);
	while(q.size()>0){
		int i=q.front();
	//	cout<<i<<" ";
		q.pop_front();
		for(auto it=adj[i].begin();it!=adj[i].end();it++){
			if(!visited[*it]){
			dist[*it]=dist[i]+1;
			q.push_back(*it);
			visited[*it]=true;
		}
	}
	}
	return dist[v];
}
int main(){
int n = 9; 
    vector <int> edges[9]; 
    addEdge(edges, 0, 1); 
    addEdge(edges, 0, 7); 
    addEdge(edges, 1, 7); 
    addEdge(edges, 1, 2); 
    addEdge(edges, 2, 3); 
    addEdge(edges, 2, 5); 
    addEdge(edges, 2, 8); 
    addEdge(edges, 3, 4); 
    addEdge(edges, 3, 5); 
    addEdge(edges, 4, 5); 
    addEdge(edges, 5, 6); 
    addEdge(edges, 6, 7); 
    addEdge(edges, 7, 8); 
    int u = 0; 
    int v = 5;
	cout<<BFS(edges,u,v,n);
	return 0;
}
