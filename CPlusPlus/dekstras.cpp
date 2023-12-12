#include<bits/stdc++.h> 
using namespace std; 
#define INF 0x3f3f3f3f 
#define V 9 
vector<pair<int,int>> adj[10000];
void printPath(vector<int> path,int j){
	if(path[j]==-1)
		return;
	printPath(path,path[j]);
	cout<<"-"<<j;
}
void addEdge(int u, int v, int w) 
{ 
	adj[u].push_back(make_pair(v, w)); 
	adj[v].push_back(make_pair(u, w)); 
} 
void shortestPath(int src) 
{ 
	list<pair<int,int>> pq; 
	vector<int> dist(V, INF);  
	pq.push_back(make_pair(0, src)); 
	vector<int> parent(V,-1);
	dist[src] = 0;
	parent[src]=-1; 
	while (!pq.empty()) 
	{ 
		int u = pq.front().second; 
		pq.pop_front(); 
		for (auto i:adj[u]){
			int v = (i).first; 
			int weight = (i).second; 
			if (dist[v] > dist[u] + weight) 
			{ 
				dist[v] = dist[u] + weight; 
				parent[v]=u;
				pq.push_back(make_pair(dist[v], v)); 
			} 
		} 
	} 
	for (int i = 0; i < V; i++) {
        cout<<i<<"\t"<<dist[i]<<'\t'<<0;
		printPath(parent,i);
		cout<<'\n'; 
	}
} 
int main() 
{ 
	addEdge(0, 1, 4); 
	addEdge(0, 7, 8); 
	addEdge(1, 2, 8); 
	addEdge(1, 7, 11); 
	addEdge(2, 3, 7); 
	addEdge(2, 8, 2); 
	addEdge(2, 5, 4); 
	addEdge(3, 4, 9); 
	addEdge(3, 5, 14); 
	addEdge(4, 5, 10); 
	addEdge(5, 6, 2); 
	addEdge(6, 7, 1); 
	addEdge(6, 8, 6); 
	addEdge(7, 8, 7); 

	shortestPath(0); 

	return 0; 
} 

