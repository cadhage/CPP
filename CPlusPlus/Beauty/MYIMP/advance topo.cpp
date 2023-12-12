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
	vector<int> in_degree(V, 0); 
	for (int u=0; u<V; u++) 
	{  
		for (auto itr: adj[u]) 
			in_degree[itr]++; 
	} 
	queue<int> q; 
	for (int i = 0; i < V; i++) 
		if (in_degree[i] == 0) 
			q.push(i); 
	int cnt = 0; 
	vector <int> top_order; 
	while (!q.empty()) 
	{ 
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
