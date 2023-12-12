// C++ program to find root which gives minimum height to tree 
#include <bits/stdc++.h> 
using namespace std; 
vector<int> adj[1000];
int degree[1000];
void addEdge(int v, int w) 
{ 
	adj[v].push_back(w); // Add w to v’s list 
	adj[w].push_back(v); // Add v to w’s list 
	degree[v]++;		 // increment degree of v by 1 
	degree[w]++;		 // increment degree of w by 1 
} 
vector<int> rootForMinimumHeight(int V) 
{ 
	queue<int> q; 

	// first enqueue all leaf nodes in queue 
	for (int i = 0; i < V; i++) 
		if (degree[i] == 1) 
			q.push(i); 

	// loop untill total vertex remains less than 2 
	while (V > 2) 
	{ 
		for (int i = 0; i < q.size(); i++) 
		{ 
			int t = q.front(); 
			q.pop(); 
			V--; 

			// for each neighbour, decrease its degree and 
			// if it become leaf, insert into queue 
			for (auto j = adj[t].begin(); j != adj[t].end(); j++) 
			{ 
				degree[*j]--; 
				if (degree[*j] == 1) 
					q.push(*j); 
			} 
		} 
	} 

	// copying the result from queue to result vector 
	vector<int> res; 
	while (!q.empty()) 
	{ 
		res.push_back(q.front()); 
		q.pop(); 
	} 
	return res; 
} 

// Driver code to test above methods 
int main() 
{ 
	//Graph g(6); 
	addEdge(0, 3); 
	addEdge(1, 3); 
	addEdge(2, 3); 
	addEdge(4, 3); 
	addEdge(5, 4); 

	vector<int> res = rootForMinimumHeight(6); 
	for (int i = 0; i < res.size(); i++) 
		cout << res[i] << " "; 
	cout << endl; 
} 

