#include <bits/stdc++.h>
using namespace std;
vector<int> adj[1000];
vector<int> indegree(1000,0);
vector<vector<int>> sol;
void addEdge(int x,int y){
	adj[x].push_back(y);
	indegree[y]++;
}
 
void topologicalSort(int V) 
{ 
	// Create a vector to store indegrees of all 
	// vertices. Initialize all indegrees as 0. 
	vector<int> in_degree(V, 0); 

	// Traverse adjacency lists to fill indegrees of 
	// vertices. This step takes O(V+E) time 
	for (int u=0; u<V; u++) 
	{  
		for (auto itr: adj[u]) 
			in_degree[itr]++; 
	} 

	// Create an queue and enqueue all vertices with 
	// indegree 0 
	queue<int> q; 
	for (int i = 0; i < V; i++) 
		if (in_degree[i] == 0) 
			q.push(i); 

	// Initialize count of visited vertices 
	int cnt = 0; 

	// Create a vector to store result (A topological 
	// ordering of the vertices) 
	vector <int> top_order; 

	// One by one dequeue vertices from queue and enqueue 
	// adjacents if indegree of adjacent becomes 0 
	while (!q.empty()) 
	{ 
		// Extract front of queue (or perform dequeue) 
		// and add it to topological order 
		int u = q.front(); 
		q.pop(); 
		top_order.push_back(u); 
		for (int itr :adj[u]) 

			// If in-degree becomes zero, add it to queue 
			if (--in_degree[itr] == 0) 
				q.push(itr); 

		cnt++; 
	} 

	// Check if there was a cycle 
	if (cnt != V) 
	{ 
		cout << "There exists a cycle in the graph\n"; 
		return; 
	} 

	// Print topological order 
	for (int i=0; i<top_order.size(); i++) 
		cout << top_order[i] << " "; 
	cout << endl; 
} 
int main(){
	int V,m;cin>>V>>m;
	for(int i=0;i<m;i++){
		int x,y;cin>>x>>y;
		//x--;y--;
		addEdge(x,y);
	}
	topologicalSort(V);
	return 0;
}
