#include <bits/stdc++.h>
using namespace std;
void dfs(vector<int> adj[], int node, int arival) {
	cout<<node<<" ";
	for(auto i=adj[node].begin(); i!=adj[node].end(); i++){
		int n=a;
		if(n!=arival)
			dfs(adj,n,node);
	}
}
int main() 
{ 
int nodes = 5; 

	// Adjacency list 
	vector<int> list[10000]; 

	// Designing the tree 
	list[1].push_back(2); 
	list[2].push_back(1); 

	list[1].push_back(3); 
	list[3].push_back(1); 

	list[2].push_back(4); 
	list[4].push_back(2); 

	list[3].push_back(5); 
	list[5].push_back(3); 

	// Function call 
	dfs(list, 1, 0); 

	return 0; 
}
