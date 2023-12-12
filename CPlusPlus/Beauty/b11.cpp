#include <bits/stdc++.h> 
using namespace std; 
vector<int> adj[10000];
#define V 6
vector<int> indegree(10000,0);
vector<int> visited(10000,false);
void addEdge(int v, int w) 
{ 
	adj[v].push_back(w);
	indegree[w]++; 
} 
vector<int> topologicalSort() 
{ 
	vector<int> topological; 
	queue<int> q; 
	for (int i = 0; i < V; i++) 
		if (indegree[i] == 0) 
			q.push(i); 
	while (!q.empty()) 
	{ 
		int t = q.front(); 
		q.pop(); 
		topological.push_back(t); 
		for (auto j: adj[t]) 
		{ 
			indegree[j]--; 
			if (indegree[j] == 0) 
				q.push(j); 

		} 
	} 
	return topological; 
} 
void maximumEdgeAddtion() 
{  
	vector<int> topo = topologicalSort(); 
	for (int i = 0; i < topo.size(); i++) 
	{ 
		int t = topo[i]; 
		for (auto j :adj[t]) 
			visited[j] = true; 
		for (int j = i + 1; j < topo.size(); j++) 
		{ 
			if(!visited[topo[j]]) 
				cout << t << "-" << topo[j] << "\n"; 
			visited[topo[j]] = false; 
		} 
	} 
} 
int main() 
{  
	addEdge(5, 2); 
	addEdge(5, 0); 
	addEdge(4, 0); 
	addEdge(4, 1); 
	addEdge(2, 3); 
	addEdge(3, 1); 
	maximumEdgeAddtion(); 
	return 0; 
} 

