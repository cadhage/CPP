#include <bits/stdc++.h>
using namespace std;
vector<int> adj[100000];
int V=7;
void addEdge(int a,int b){
	adj[a].push_back(b);
}
void DFSUtil(int v, vector<bool> &visited) 
{ 
	visited[v] = true; 
	for (auto it:adj[v]) 
		if (!visited[it]) 
			DFSUtil(it, visited); 
} 
int findMother() 
{ 
	vector <bool> visited(V, false); 
	int v = 0; 
	for (int i = 0; i < V; i++) 
	{ 
		if (!visited[i]) 
		{ 
			DFSUtil(i, visited); 
			v = i; 
		} 
	} 
	fill(visited.begin(), visited.end(), false); 
	DFSUtil(v, visited); 
	for (int i=0; i<V; i++) 
		if (!visited[i]) 
			return -1; 
	return v; 
} 
int main(){
	addEdge(0, 1); 
    addEdge(0, 2); 
    addEdge(1, 3); 
    addEdge(4, 1); 
    addEdge(6, 4); 
    addEdge(5, 6); 
    addEdge(5, 2); 
    addEdge(6, 0); 
    cout << "A mother vertex is " << findMother(); 
	return 0;
}
