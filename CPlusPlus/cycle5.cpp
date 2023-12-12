// C++ program to find out whether a given graph is 
// Bipartite or not 
#include <bits/stdc++.h> 
#include <queue> 
#define V 4 

using namespace std; 

// This function returns true if graph G[V][V] contains 
// odd cycle, else false 
bool containsOdd(int G[][V], int src) 
{ 
	// Create a color array to store colors assigned 
	// to all veritces. Vertex number is used as index 
	// in this array. The value '-1' of colorArr[i] 
	// is used to indicate that no color is assigned to 
	// vertex 'i'. The value 1 is used to indicate first 
	// color is assigned and value 0 indicates second 
	// color is assigned. 
	int colorArr[V]; 
	for (int i = 0; i < V; ++i) 
		colorArr[i] = -1; 
	list<int> q;
	// Assign first color to source 
	colorArr[src] = 1; 
	q.push_back(src);

	// Run while there are vertices in queue (Similar to BFS) 
	while (q.size()>0) 
	{ 
		// Dequeue a vertex from queue 
		int u = q.front(); 
		q.pop_front(); 

		// Return true if there is a self-loop 
		if (G[u][u] == 1) 
		return true; 

		// Find all non-colored adjacent vertices 
		for (int v = 0; v < V; ++v) 
		{ 
			// An edge from u to v exists and destination 
			// v is not colored 
			if (G[u][v] && colorArr[v] == -1) 
			{ 
				// Assign alternate color to this adjacent 
				// v of u 
				colorArr[v] = 1 - colorArr[u]; 
				q.push_back(v); 
			} 

			// An edge from u to v exists and destination 
			// v is colored with same color as u 
			else if (G[u][v] && colorArr[v] == colorArr[u]) 
				return true; 
		} 
	} 

	// If we reach here, then all adjacent 
	// vertices can be colored with alternate 
	// color 
	return false; 
} 

// Driver program to test above function 
int main() 
{ 
	int G[][V] = {{0, 1, 0, 1}, 
		{1, 0, 1, 0}, 
		{0, 1, 0, 1}, 
		{1, 0, 1, 0} 
	}; 

	containsOdd(G, 0) ? cout << "Yes" : cout << "No"; 
	return 0; 
} 

