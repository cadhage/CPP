// A C++ program to implement greedy algorithm for graph coloring 
#include <iostream> 
#include <list>
#include <bits/stdc++.h> 
using namespace std; 
vector<int> adj[1000];
vector<int> result(1000,-1);  
vector<bool> available(1000,false); 
void addEdge(int v, int w) 
{ 
	adj[v].push_back(w); 
	adj[w].push_back(v); // Note: the graph is undirected 
} 
void greedyColoring(int V) 
{ 
	for (int u = 1; u < V; u++) 
	{ 
		for (auto i:adj[u]) 
			if (result[i] != -1) 
				available[result[i]] = true;  
		for (int cr = 0; cr < V; cr++) 
			if (!available[cr]) 
				break; 
		result[u] = cr; // Assign the found color 
		for (auto i:adj[u]) 
			if (result[i] != -1) 
				available[result[i]] = false; 
	} 
	for (int u = 0; u < V; u++) 
		cout << "Vertex " << u << " ---> Color "
			<< result[u] << endl; 
} 
int main() 
{ 
	addEdge(0, 1); 
	addEdge(0, 2); 
	addEdge(1, 2); 
	addEdge(1, 3); 
	addEdge(2, 3); 
	addEdge(3, 4); 
	cout << "Coloring of graph 1 \n"; 
	greedyColoring(5); 
	return 0; 
} 

