// A C++ Program to detect cycle in a graph 
#include<bits/stdc++.h> 
using namespace std;
int V= 4 ;
vector<int> adj[10000];
void addEdge(int v, int w) 
{ 
	adj[v].push_back(w); // Add w to v’s list. 
} 
vector<bool> recStack(10000,false),visited(10000,false); 
bool isCyclicUtil(int v) 
{ 
	if(visited[v] == false) 
	{ 
		// Mark the current node as visited and part of recursion stack 
		visited[v] = true; 
		recStack[v] = true; 
		for(auto i:adj[v]) 
		{ 
			if ( !visited[i] && isCyclicUtil(i) ) 
				return true; 
			else if (recStack[i]) 
				return true; 
		} 

	} 
	recStack[v] = false; // remove the vertex from recursion stack 
	return false; 
} 

// Returns true if the graph contains a cycle, else false. 
// This function is a variation of DFS() in https://www.geeksforgeeks.org/archives/18212 
bool isCyclic() 
{
	for(int i = 0; i < V; i++) 
		if (isCyclicUtil(i)) 
			return true; 

	return false; 
} 

int main() 
{  
	addEdge(0, 1); 
	addEdge(0, 2); 
	addEdge(1, 2); 
	addEdge(2, 0); 
	addEdge(2, 3); 
	addEdge(3, 3); 

	if(isCyclic()) 
		cout << "Graph contains cycle"; 
	else
		cout << "Graph doesn't contain cycle"; 
	return 0; 
} 

